#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const unsigned int MaxFrameBufferSize = 100;
    unsigned int frameBuffer[MaxFrameBufferSize][MaxFrameBufferSize];

    unsigned int screenSize;
    std::cin >> screenSize;

    for (unsigned int x = 0; x < screenSize; ++x)
    {
        for (unsigned int y = 0; y < screenSize; ++y)
        {
            std::cin >> frameBuffer[x][y];
        }
    }

    const unsigned int diagonalsCount = screenSize * 2 - 1;

    for (unsigned int diagonal = 0; diagonal < diagonalsCount; ++diagonal)
    {
        const bool firstHalf = diagonal < screenSize;
        unsigned int subFrameSize = firstHalf ? 1 + diagonal : diagonalsCount - diagonal;

        //dumping diagonal
        for (int i = 0; i < subFrameSize; ++i)
        {
            const unsigned int coordOnDiagonalX = firstHalf ? i : i + screenSize - subFrameSize;
            const unsigned int coordOnDiagonalY = (firstHalf ? subFrameSize : screenSize) - i - 1;

            std::cout << frameBuffer[coordOnDiagonalY][coordOnDiagonalX] << " ";
            //std::cout << coordOnDiagonalX << ":" << coordOnDiagonalY << "\t" << frameBuffer[coordOnDiagonalY][coordOnDiagonalX] <<
            //          std::endl;
        }
    }
}