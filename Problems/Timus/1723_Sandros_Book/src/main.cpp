/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

//#define ONLINE_JUDGE

typedef vector<int> VectorInt;

class ProblemSolver
{
public:
    ProblemSolver(const string &aStr) :
        mStr(aStr)
    {

    }
    virtual ~ProblemSolver()
    {

    }

    const string &getString()
    {
        return mStr;
    }

    virtual string resolve() = 0;
private:
    string mStr;
};

class Variant3 : public ProblemSolver
{
public:
    Variant3(const string &aStr) :
        ProblemSolver(aStr)
    {

    }

    virtual ~Variant3()
    {

    }

    virtual string resolve()
    {
        VectorInt result;
        map<char, size_t> ranks;

        for(size_t i = 0; i < getString().length(); ++i)
        {
            ++ranks[getString()[i]];
        }

        map<char, size_t>::iterator it = ranks.begin();
        char val = it->first;
        size_t max = it->second;


        for(++it; it != ranks.end(); ++it)
        {
            if(it->second > max)
            {
                max = it->second;
                val = it->first;
            }
        }

        char rr[2] = "a";
        rr[0] = val;
        rr[1] = 0;
        return string(rr);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char buffer[51];
    scanf("%s", buffer);

    const string source(buffer);

    Variant3 var(source);
    printf(var.resolve().c_str());

    return 0;
}
