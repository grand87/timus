/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <string>
#include <assert.h>

using namespace std;

//#define ONLINE_JUDGE

string decrypt(const string &src)
{
    string step1;
    string step2;
    string step3;

    const size_t length = strlen(src.c_str());

    step1.resize(length);
    step2.resize(length);
    step3.resize(length);
    
    for(size_t i = 0; i < length; ++i)
    {
        step1[i] = src[i] - 'a';
        
        if(i == 0)
            step2[i] = step1[i] - 5;
        else
            step2[i] = step1[i] + 26 - step1[i - 1];

        if(step2[i] >= 26)
            step2[i] -= 26;
        else
        if(step2[i] < 0)
            step2[i] += 26;

        step3[i] = step2[i] + 'a';
    }
    return step3;
}

void extractMiddleSymbol(const string &src, string& result, size_t left, size_t right)
{
    if(left < src.length() && right < src.length())
    {
        if(left > right)
            result +=src[left - 1];
        else
        if(left == right)
            result +=src[left];
        else
        {
            const size_t middle = (left + right) / 2;
            result += src[middle - 1];

    //        if(left != middle)
                extractMiddleSymbol(src, result, left, middle);
            
    //        if(right != middle + 1)
                extractMiddleSymbol(src, result, middle + 1, right);
        }
    }
}

string encrypt(const string &src)
{
    const size_t length = strlen(src.c_str());
    if(length == 1)
        return src;
    
    string result;
    extractMiddleSymbol(src, result, 1, length);
    return result;
}


#define DEBUG_RUN

#ifdef DEBUG_RUN

bool testCase(string src)
{
    string result1 = encrypt(src);
    string result2 = decrypt(result1);
    size_t d = result2.compare(src);
    return d == 0;
}

#endif

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    string buffer("");
    buffer.resize(101);

#ifdef DEBUG_RUN

    string test = encrypt("ab");
    assert(test.compare(string("ab")) == 0);

    test = encrypt("abcd");
    assert(test.compare("bacd") == 0);

    test = encrypt("abcde");
    assert(test.compare("cabde") == 0);

    test = encrypt("Vasya likes soup.");
    assert(test.compare("kyaVs alisse uop.") == 0);

    assert(testCase("Vasya likes soup."));
    assert(testCase("orthography"));
#endif

    scanf("%s", &buffer[0]);
    string result = decrypt(buffer);
    printf("%s", result.c_str());

    return 0;
}
