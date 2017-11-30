#include <iostream>

using namespace std;

void rotateMatrix(const bool source[4][4], bool target[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            target[j][3 - i] = source[i][j];
        }
}

void printPassword(const char data[4][4], const bool matrix[4][4])
{
    char buff[2];
    buff[1] = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if (matrix[i][j])
            {
                buff[0] = data[i][j];
                cout << buff;
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    bool matrix[4][4][4];
    char data[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            char v;
            cin >> v;
            matrix[0][i][j] = v == 'X';
        }
    
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> data[i][j];

    for (int i = 0; i < 4; ++i)
    {
        printPassword(data, matrix[i]);
        if(i < 3)
            rotateMatrix(matrix[i], matrix[i + 1]);
    }
}