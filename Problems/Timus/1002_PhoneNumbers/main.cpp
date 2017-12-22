#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getDigit(char a)
{
    switch (a)
    {
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

int CharToDigitMap[] = {
    2,//a
    2,//b
    2,//c
    3,//d
    3,//e
    3,//f
    4,//g
    4,//h
    1,//i
    1,//j
    5,//k
    5,//l
    6,//m
    6,//n
    0,//o
    7,//p
    0,//q
    7,//r
    7,//s
    8,//t
    8,//u
    8,//v
    9,//w
    9,//x
    9,//y
    0//z
};

//could be speed up if use map[char, digit]
void encodeWord(const char word[51], char phone[51])
{
    int i = 0;
    while (word[i])
    {
        phone[i] = CharToDigitMap[word[i] - 'a'] + '0';
        ++i;
    }
    phone[i] = 0;
}

struct word
{
    word(const string& v) : value(v), len(v.length())
    {

    }

    string value;
    mutable string phone;
    int len;

    const string& getPhone() const
    {
        if (phone.length() == 0)
        {
            phone.resize(len);
            encodeWord(value.c_str(), &phone[0]);
        }
        return phone;
    }
};

typedef vector<word> words;
typedef pair<int, int> option;
typedef vector<option> OptionList;
struct OptioneDefinition
{
    OptioneDefinition()
    {
        fixed = false;
        terminate = false;
    }

    OptionList list;
    bool fixed;
    bool terminate;
};
typedef vector<OptioneDefinition> OptionsList;

bool check(const word& w, const char phone[101], int len, int position)
{
    //this might be optimised based on prehash generation for every word & phone
    const string &p = w.getPhone();
    for (int i = 0; i < w.len; ++i)
        if (p[i] != phone[position + i])
            return false;
    return true;
}

vector<int> getWordsForPhone(const words &wordsList, const char phone[101], int len, int position)
{
    vector<int> result;

    const int maxLen = len - position;

    for (int i = 0; i < wordsList.size(); ++i)
    {
        if (wordsList[i].len <= maxLen && check(wordsList[i], phone, len, position))
        {
            result.push_back(i);
        }
    }

    return result;
}

int getMinOption(const OptionsList& opts)
{
    int minSize = 1000000;
    if(opts.size() > 1)
        for (int i = 0; i < opts.size(); ++i)
        {
            if (opts[i].list.size() < minSize && opts[i].list.size() > 0 && opts[i].fixed)
                minSize = opts[i].list.size();
        }
    return minSize;
}

int generatePhrase(const char phone[101], int len, int position, const words dictNumber[10], OptionsList& opts, int optId = -1)
{
    //find suitable word for digit
    const int digit = phone[position] - '0';
    if (dictNumber[digit].size() > 0)
    {
        //here is the list of possible words - need to locate the shortest suitable one
        vector<int> options = getWordsForPhone(dictNumber[digit], phone, len, position);

        //iterate via every possible option
        for (int i = 0; i < options.size(); ++i)
        {
            int internalOptionID = -1;
            if (optId == -1)
            {
                opts.push_back(OptioneDefinition());
                internalOptionID = opts.size() - 1;
            }
            else
                internalOptionID = optId;
            
            if (opts[internalOptionID].fixed)
                break;

            if (opts[internalOptionID].terminate)
                break;

            opts[internalOptionID].list.push_back(option(digit, options[i]));
            //if there is already more shortes combination - need to terminate

            int mOpt = getMinOption(opts);
            if (opts[internalOptionID].list.size() <= mOpt)
            {
                //check is there should be added more words or it is final iteration
                if (dictNumber[digit][options[i]].len == len - position)
                {
                    opts[internalOptionID].fixed = true;
                    return internalOptionID;
                }

                // need to continue possible options

                if (generatePhrase(phone, len, position + dictNumber[digit][options[i]].len, dictNumber, opts, internalOptionID) == -1)
                {
                    opts[internalOptionID].list.clear();
                    opts[internalOptionID].terminate = true;
                }
            }
            else
                opts[internalOptionID].terminate = true;
        }
    }
    return optId == -1 ? -1 : opts[optId].fixed ? optId : -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    
    while (true)
    {
        char phone[101];

        cin >> phone;
        if (phone[0] == '-')
            break;

        int dictSize = 0;
        cin >> dictSize;

        words dictNumber[10];
        for (int i = 0; i < dictSize; ++i)
        {
            char w[51];
            cin >> w;
            const int id = getDigit(w[0]);
            dictNumber[id].push_back(word(w));
        }

        for (int i = 0; i < 10; ++i)
        {
            sort(dictNumber[i].begin(), dictNumber[i].end(), [](const word &a, const word &b) {
                return a.len > b.len;
            });
        }

        const int len = strlen(phone);
        OptionsList opts;

        generatePhrase(phone, len, 0, dictNumber, opts);

        int shortes = 100000;
        int index = -1;

        for (int i = 0; i < opts.size(); ++i)
        {
            if (opts[i].list.size() > 0 && opts[i].list.size() < shortes && opts[i].fixed)
            {
                shortes = opts[i].list.size();
                index = i;
            }
        }
        if (index == -1)
        {
            cout << "No solution." << endl;
        }
        else
        {
            for (int j = 0; j < opts[index].list.size(); ++j)
                cout << dictNumber[opts[index].list[j].first][opts[index].list[j].second].value << " ";
            cout << endl;
        }
    }
}