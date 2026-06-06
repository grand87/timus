#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>
#include <string_view>

using namespace std;
//for performance implement via array
static int getDigit(char a) {
    switch (a) {
        case 'i':
        case 'j':
            return 1;
        case 'a':
        case 'b':
        case 'c':
            return 2;
        case 'd':
        case 'e':
        case 'f':
            return 3;
        case 'g':
        case 'h':
            return 4;
        case 'k':
        case 'l':
            return 5;
        case 'm':
        case 'n':
            return 6;
        case 'p':
        case 'r':
        case 's':
            return 7;
        case 't':
        case 'u':
        case 'v':
            return 8;
        case 'w':
        case 'x':
        case 'y':
            return 9;
        case 'o':
        case 'q':
        case 'z':
            return 0;
    }
    return -1;
}

static const int CharToDigitMap[] = {
    2,  // a
    2,  // b
    2,  // c
    3,  // d
    3,  // e
    3,  // f
    4,  // g
    4,  // h
    1,  // i
    1,  // j
    5,  // k
    5,  // l
    6,  // m
    6,  // n
    0,  // o
    7,  // p
    0,  // q
    7,  // r
    7,  // s
    8,  // t
    8,  // u
    8,  // v
    9,  // w
    9,  // x
    9,  // y
    0   // z
};

using Dict = map<string, string>;
using Phrase = vector<int>; // index word from dict

string encodeInNumbers(const string& word) {
    string result(word);
    for (int i =0; i < word.size(); i++) {
        // store numbers as a chars in dict explicitly
        result[i] = CharToDigitMap[word[i] - 'a'] + '0';
    }
    return result;
}

size_t find(const string_view& phone, const string& sequence) {
    // can this word/sequnce fit?
    //const int wordLen = sequence.size();
    //if (phone.size() < string::npos) {
    //    return 0;
    //}
  
    // per char comparison starting from startPos
    // this might be optimised based on prehash generation for every word & phone
    const size_t pos = phone.find(sequence);
    return pos;
}

bool bt(const string_view& phone, const Dict& dict, Phrase& phrase, vector<Phrase>& result, bool addToResult) {
    if (phone.size() == 0) {
        return true;
    }
    // terminate conditions
    int wordIdxNext = 0;
    for (const auto& [word, sequence] : dict) {
        const int wordIdx = wordIdxNext++;
        // check the word if: can it make a valid sequence of digits
        const size_t sequencePos = find(phone, sequence);
        if (sequencePos == string::npos) {
            // try another word
            continue;
        }

        // proper sequnce was located starting at sequencePos
        // repeat recursively for left & right parts
        // search for another word to fit to the left
        // and if there is space after word - search for another word to fit to the right++
        // process left
        auto left = phone.substr(0, sequencePos);
        Phrase toTheLeft;
        if (left.size() && !bt(left, dict, toTheLeft, result, false)) {
            // there is subphrase to the left but do not find fit for it
            continue;
        }

        // add current middle word to the left and append the right part
        toTheLeft.push_back(wordIdx);

        // if left processed & sub phrase located - process right
        const int rightStartPos = sequencePos + sequence.size();
        auto right = phone.substr(rightStartPos, phone.size() - rightStartPos);
        if (right.size()) {
            Phrase toTheRight;
            if (!bt(right, dict, toTheRight, result, false)) {
                // there is subphrase to the right but do not find fit for it
                continue;
            }
            toTheLeft.insert(toTheLeft.end(), toTheRight.begin(), toTheRight.end());
        }

        if (addToResult) {
            result.push_back(toTheLeft);
        } else {
            phrase = toTheLeft;
            // return once first phrase located
            return true;
        }
    }

    return false;
}

void addToDict(Dict& dict, string w) {
    // dict[w] = encodeInNumbers(w);
    dict[encodeInNumbers(w)] = w;
}

bool test1() {
    Dict dict;
    addToDict(dict, "iad");
    addToDict(dict, "i");
    addToDict(dict, "adgk");
    addToDict(dict, "g");
    addToDict(dict, "k");

    Phrase p;
    vector<Phrase> r;

    bt("12345", dict, p, r, true);

    return true;
}

vector<string> wordBreakBacktracking(char phoneNumber[101], const Dict& dict) {
    /*
        backtracking?

        Loop over all words in the dict to pick the word to start sequence with,
        in recursion pick any remaining word to continue with backtracking

        [w1, w2, w3, w4]

        w1                                      push 0  (0)
        --w2                                    push 1  (01)
        ----w3                                  push 2  (012)
            too long/does not form the word     pop     (01)
        ----w4                                  push 3  (013)
            match                               store 0 1 3 into result arr
            return                              pop     (01)
        --retrun                                pop     (0)
        --w3                                    push 2 (02)
    */

    /*
     *   backtracking version 2
     * 1. search for the longest word in the sequence
     * 2. once found intitial sequence split in 2 parts
     * 3. repeat recursively for 2 parts
     */

    vector<string> resultWords;
    Phrase phrase;          // indexes of words in dict
    vector<Phrase> result;  // set of phrases for current phone number & dict;

    // try every word to find in the sequence starting from the longest one
    bt(phoneNumber, dict, phrase, result, true);
    if (result.empty()) {
        cout << "No solution.\n";
        return resultWords;
    }

    int minSequence = 1000;
    int minSequenceIdx = -1;

    for (int i = 0; i < result.size(); i++) {
        if (result[i].size() < minSequence) {
            minSequence = result[i].size();
            minSequenceIdx = i;
        }
    }

    if (minSequenceIdx != -1) {
        const auto& shortestPhrase = result[minSequenceIdx];
        const int lastWordIdx = shortestPhrase.size() - 1;
        for (int wordIdx = 0; wordIdx < shortestPhrase.size(); wordIdx++) {
            auto it = dict.begin();
            advance(it, shortestPhrase[wordIdx]);
            cout << it->first;
            resultWords.push_back(it->first);
            if (wordIdx < lastWordIdx) {
                cout << " ";
            }
        }
    }
    cout << endl;
    return resultWords;
}

void wordBreakTrie(const string& phone, const Dict& dict) {
    // use trie for quick word search

    // build trie from dict

    // loop over all prefixes and store shortes number of words in dp map
}


vector<string> wordBreakDP(const string& s, const Dict& dict) {
    const int n = s.size();

    // minimal number of splits up to this position
    vector<int> dp(n + 1, INT_MAX);
    vector<string_view> dps(n + 1);
    dp[n] = 0;

    // Traverse through the given string from right to left
    for (int i = n - 1; i >= 0; i--) {

        for (int j = i; j < n; j++) {
        
            // check condition if substring can be segmented
            if (dp[j + 1] == INT_MAX) {
                continue;
            }

            // if so - checkif current substring is part of the dictionary

            std::string_view tmp(s.c_str() + i, j - i  + 1);
            auto word = dict.find(string(tmp));
            
            if (word != dict.end()) {
                dps[i] = word->second;
                dp[i] = min(dp[i], 1 + dp[j + 1]);
            }        
        }
    }

    vector<string> resultWords;
    if (dp[0] == INT_MAX) {
        cout << "No solution.\n";  
    } else {
        int start = 0;
        while (start < n) {
            cout << dps[start];
            resultWords.push_back(string(dps[start]));
            start += dps[start].size();
            if (start < n) {
                cout << " ";
            }      
        }
        cout << "\n";
    }
    return resultWords;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);

    // unit tests local only
    //assert(test1() == true);
#endif

    while (true) {
        char phoneNumber[101];
        Dict dict; // <word, number representation> 

        cin >> phoneNumber;
        if (strlen(phoneNumber) == 0) {
            break;
        }
        if (phoneNumber[0] == '-') {
            break;
        }

        int dictSize = 0;
        cin >> dictSize;

        for (int i = 0; i < dictSize; i++) {
            char w[51];
            cin >> w;
            addToDict(dict, w);
        }

        vector<string> result1 = wordBreakBacktracking(phoneNumber, dict);

        vector<string> result2 = wordBreakDP(phoneNumber, dict);

        #ifndef ONLINE_JUDGE
        assert(result1 == result2);
        #endif
        
    }
}