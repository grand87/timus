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

typedef vector<size_t> VectorInt;

class PageGenerator
{
public:
    PageGenerator(size_t aLinesPerPage, size_t aLettersPerLine) :
        linesPerPage(aLinesPerPage),
        lettersPerLine(aLettersPerLine),
        freeAtLine(aLettersPerLine),
        lastLine(0)
    {

    }

    size_t getPagesCount() const
    {
        size_t fPages = (lastLine+1) / linesPerPage;
        if((lastLine+1) % linesPerPage != 0)
            ++fPages;
        return fPages;
    }

    void addWord(const std::string& newWord)
    {
        if(freeAtLine == 0)
            insertNewLine();

        const size_t l = newWord.length();

        if(l > freeAtLine)
            insertNewLine();

        freeAtLine -= l;

        if(freeAtLine > 0)
            --freeAtLine;
    }

private:

    void insertNewLine()
    {
        ++lastLine;
        freeAtLine = lettersPerLine;
    }

    const size_t linesPerPage;
    const size_t lettersPerLine;
    size_t freeAtLine;
    size_t lastLine;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    size_t linesPerPage = 0;
    size_t lettersPerLine = 0;

    scanf("%d", &linesPerPage);
    scanf("%d", &lettersPerLine);

    PageGenerator solver(linesPerPage, lettersPerLine);

    size_t wordsCount = 0;
    scanf("%d", &wordsCount);

    char *buffer = new char[lettersPerLine + 1];
    size_t i = 0;
    while(i++ < wordsCount)
    {
        size_t value = 0;
        scanf("%s", buffer);
        solver.addWord(buffer);
    }

    printf("%d", solver.getPagesCount());

    delete[] buffer;

    return 0;
}
