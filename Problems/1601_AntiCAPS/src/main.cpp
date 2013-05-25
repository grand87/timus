/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

const char terminator[] = {'.', '!', '?'};

bool isBig(char letter)
{
    return letter >= 65 && letter <= 90;
}

bool isSmall(char letter)
{
    return letter >= 97 && letter <= 122;
}

bool isTerminator(char letter)
{
    return letter == terminator[0] || letter == terminator[1] || letter == terminator[2];
}

bool normalize(const char* source, char * const result, bool isNew)
{
    size_t i = 0;
    bool sentenceTerminated = false;
    bool firstLetterLocated = !isNew;

    while(char current = source[i])
    {
        if((isBig(current) && !firstLetterLocated) || (isNew && isSmall(current)))
        {
            if(isSmall(current))
                current -= 32;
            firstLetterLocated = true;
            isNew = false;
            sentenceTerminated = false;
        }
        else        
        if(firstLetterLocated && isBig(current))
        {
            current += 32;
            sentenceTerminated = false;
        }
        else
        if(isTerminator(current))
        {
            isNew = true;
            firstLetterLocated = false;
            sentenceTerminated = true;
        }

        result[i] = current;
        ++i;
    }
    result[i] = 0;
    if(firstLetterLocated)
        return sentenceTerminated;
    else
        return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    char buffer[10001] = "";
    char result[10001] = "";

    bool isNew = true;

    bool isFirstLine = true;

    while(!feof(stdin))
    {
        gets(buffer);
        isNew = normalize(buffer, result, isNew);
        if(isFirstLine)
            isFirstLine = !isFirstLine;
        else
            printf("\n");
        printf("%s", result);
    }

    return 0;
}
