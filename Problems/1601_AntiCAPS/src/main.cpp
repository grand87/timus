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

class Processor
{
    bool isNew;

public:
    Processor()
    {
        isNew = true;
    }

    char process(char c)
    {
        char result = c;
        if(isNew)
        {
            if(isSmall(c))
            {
                c -= 32;
                isNew = false;
            }
            else if(isBig(c))
                isNew = false;
        }
        else
        if(isBig(c))
        {
            c += 32;
        }
        else
            if(isTerminator(c))
                isNew = true;
        return c;
    }
};

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

    Processor processor;

    while(!feof(stdin))
    {
        char c;
        scanf("%c", &c);

        c = processor.process(c);
        printf("%c", c);
    }

    return 0;
}
