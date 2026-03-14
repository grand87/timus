#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

// could be speed up if use map[char, digit]
// TODO: replace with string_view
void encodeWord(const char* word, char disgits[51]) {
    int i = 0;
    while (word[i]) {
        // store numbers as a chars in dict explicitly
        disgits[i] = CharToDigitMap[word[i] - 'a'] + '0';
        ++i;
    }
    disgits[i] = 0;
}

bool check(const string& phone, const char* sequence, int startPos) {
    // can this word/sequnce fit?
    const int wordLen = strlen(sequence);
    if (phone.size() < startPos + wordLen) {
        return 0;
    }
    
    // per char comparison starting from startPos
    // this might be optimised based on prehash generation for every word & phone
    for (int i = 0; i < wordLen; ++i) {
        if (sequence[i] != phone[startPos + i]) {
            return false;
        }
    }
    return true;
}

bool bt(const string& phone, const vector<string>& dict, int startPos, int wordIdx, vector<int> phrase, vector<vector<int>>& result) {
    // terminate conditions
    if (wordIdx == dict.size()) {
        return false;
    }
    if (find(phrase.begin(), phrase.end(), wordIdx) != phrase.end()) {
        return false;
    }

    // analyze the word and if it fits - add into phrase and continue
    
    char numberSequence[51];
    encodeWord(dict[wordIdx].c_str(), numberSequence);

    // check the word if: can it make a valid sequence of digits starting from current position
    // if it does match - add into phrase
    // return otherwise
    if (check(phone, numberSequence, startPos)) {
        phrase.push_back(wordIdx);
    } else {
        return false;
    }

    const int nextStartPos = startPos + strlen(numberSequence);
    
    // is phone fully processed?
    if (nextStartPos == phone.size()) {
        result.push_back(phrase);
        return true;
    }
  
    // if not - build phrase with all remaining word in dict except those which are already in use
    for (int nextWordIdx = 0; nextWordIdx < dict.size(); nextWordIdx++) {
        if (wordIdx == nextWordIdx) {
            // same word already in use - skip
            continue;
        }
        if (bt(phone, dict, nextStartPos, nextWordIdx, phrase, result)) {
            // once solution is found - return immidiately
            return false;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

    while (true) {
        char phoneNumber[101];
        vector<string> dict;

        cin >> phoneNumber;
        if (phoneNumber[0] == '-')
            break;

        int dictSize = 0;
        cin >> dictSize;

        for (int i = 0; i < dictSize; ++i) {
            char w[51];
            cin >> w;
            dict.push_back(string(w));
        }

        // sort dict by words len
        sort(dict.begin(), dict.end(), [](const string& a, const string& b) { return a.size() > b.size(); });

        /*
            Dynamic programming?

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

        vector<int> phrase;    // indexes of words in dict
        vector<vector<int>> result;  // set of phrases for current phone number & dict;

        // try every word to start sequence with
        for (int startWordIdx = 0; startWordIdx < dict.size(); startWordIdx++) {
            if (bt(phoneNumber, dict, 0, startWordIdx, phrase, result)) {
                break;
            }
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
                cout << dict[shortestPhrase[wordIdx]];
                if (wordIdx < lastWordIdx) {
                    cout << " ";
                }
            }
        } else {
            cout << "No solution.";
        }
        cout << endl;
    }
}