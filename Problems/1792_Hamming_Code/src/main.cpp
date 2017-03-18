/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>

//#define ONLINE_JUDGE

bool checkHamming(const bool * code)
{
    //return 
    //    code[4] == (code[1] + code[2] + code[3] % 2) &&
    //    code[5] == (code[0] + code[2] + code[3] % 2) &&
    //    code[6] == (code[0] + code[1] + code[3] % 2);

    bool check = code[4] == ((code[1] + code[2] + code[3]) % 2);
    if(!check)
        return false;
    check = code[5] == ((code[0] + code[2] + code[3]) % 2);
    if(!check)
        return false;
    check = code[6] == ((code[0] + code[1] + code[3]) % 2);
    if(!check)
        return false;
    return true;
}

void copy(const bool * codeSrc, bool * const codeDest)
{
    for(char i = 0; i < 7; ++i)
        codeDest[i] = codeSrc[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    bool original[7];
    bool code[7];
    for(char i = 0; i < 7; ++i)
    {
        size_t value = 0;
        scanf("%d", &value);
        code[i] = value != 0;
        original[i] = code[i];
    }

    char pos = 0;

    while(!checkHamming(code) && pos < 7)
    {
        if(pos != 0)
            copy(original, code);

        code[pos] = !code[pos];
        ++pos;
    }

    for(char i = 0; i < 7; ++i)
        printf("%d ", code[i]);

    return 0;
}
