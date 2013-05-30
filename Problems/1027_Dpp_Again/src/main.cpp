/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

//#define ONLINE_JUDGE

typedef vector<size_t> VectorInt;

bool checkCorrectSymbolForOperation(char symbol)
{
    bool result = false;
    switch(symbol)
    {
    case '=':result = true; break;
    case '+':result = true; break;
    case '-':result = true; break;
    case '*':result = true; break;
    case '/':result = true; break;
    case '0':result = true; break;
    case '1':result = true; break;
    case '2':result = true; break;
    case '3':result = true; break;
    case '4':result = true; break;
    case '5':result = true; break;
    case '6':result = true; break;
    case '7':result = true; break;
    case '8':result = true; break;
    case '9':result = true; break;
    default:
        result = false;
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string src;

    while(!feof(stdin))
    {
        char buffer[10001] = "";
        gets(buffer);
        src.append(buffer);
    }

    const size_t strLength = src.length();

    size_t comments = 0;
    size_t operations = 0;
    size_t operationsStart = 0;
    size_t commentStart = 0;

    bool notBalancedComments = false;
    bool notBalancedOperations = false;
    bool invalidOperationSymbol = false;

    for(size_t i = 0; i < strLength; ++i)
    {
        if(src[i] == '(')
        {
            if(comments == 0)
            {
                if(i < strLength - 1 && src[i + 1] == '*')
                {
                    ++comments;
                    commentStart = i + 1;
                }
                else
                {
                    ++operations;
                    operationsStart = i;
                }
            }
        }
        else
        if(src[i] == ')')
        {
            if(i > 0 && src[i - 1] == '*')
            {
                if(comments == 0)
                {
                    if(operations == 0)
                    {
                        notBalancedComments = true;
                        break;
                    }
                    else
                    {
                        if(operations == 0)
                        {
                            notBalancedOperations = true;
                            break;
                        }
                        --operations;
                    }
                }
                else
                {
                    if(i-1 == commentStart)
                    {
                        notBalancedComments = true;
                        break;
                    }
                    --comments;
                }
            }
            else
            {
                if(comments == 0)
                {
                    if(operations == 0)
                    {
                        notBalancedOperations = true;
                        break;
                    }
                    --operations;
                }
            }
        }
        else
        if(comments == 0)
        {
            if(operations != 0)
            {
                if(!checkCorrectSymbolForOperation(src[i]))
                {
                    invalidOperationSymbol = true;
                    break;
                }
            }
        }
    }
    
    if(comments == 0 && operations == 0 && !notBalancedComments && !notBalancedOperations && !invalidOperationSymbol)
        printf("YES");
    else
        printf("NO");

    return 0;
}

