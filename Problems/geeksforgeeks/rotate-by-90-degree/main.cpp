#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

constexpr unsigned int MatrixSize = 50;
unsigned int matrix[MatrixSize * MatrixSize] = {0};

void transpose(unsigned int *matrix, unsigned int size) {
    for (unsigned int r = 1; r < size; r++) {
        for (unsigned int c = 0; c < r ; c++) {
            const unsigned int pos = r * size + c;
            const unsigned int posT = c * size + r;
            swap(matrix[pos], matrix[posT]);
        }
    }
}

void rotateArray1(unsigned int *arr, unsigned int size) {
    const unsigned char tmp = arr[0];
    for (unsigned int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = tmp;
}

void swapArray(unsigned int *arr1, unsigned int *arr2, unsigned int size) {
    for (unsigned int i = 0; i < size; i++)
        swap(arr1[i], arr2[i]);
}

void reverseRows(unsigned int *arr, unsigned int size) {
    for (unsigned int i = 0; i < size / 2; i++) {
        swapArray(arr, arr + (size - 1 - i) * size, size);
    }
}

void shiftColumns(unsigned int *matrix, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        rotateArray1(matrix + i * size, size);
    }
}

void dumpArray(unsigned int *matrix, unsigned int size) {
    for (unsigned int j = 0; j < size * size; j++) {
        cout << matrix[j] << " ";
    }
    cout << endl;
}

void dumpMatrix(unsigned int *matrix, unsigned int size) {
    for (unsigned int r = 0; r < size; r++) {
        for (unsigned int c = 0; c < size; c++) {
            cout << matrix[r * size + c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    virtual void solve(unsigned int *matrix, unsigned int size) = 0 {

    }
};

class SolutionTranspose : public Solution {
public:
    virtual void solve(unsigned int *matrix, unsigned int size) override {
#ifdef LOCAL_TEST
        dumpArray(matrix, size);
#endif
        // transpose matrix
        transpose(matrix, size);

#ifdef LOCAL_TEST
        dumpArray(matrix, size);
#endif

        // shift columns
        reverseRows(matrix, size);
        dumpArray(matrix, size);
    }
};

inline int getByYX(unsigned int *matrix, unsigned int size, int y, int x) {
//    cout << "from " << y << " " << x << " " << endl;
    return matrix[y * size + x];
    
}

inline void setByYX(unsigned int *matrix, unsigned int size, int y, int x, int value) {
//    cout << "into " << y << " " << x << " " << endl;
    matrix[y * size + x] = value;
}

class SolutionRotate : public Solution {
public:
    virtual void solve(unsigned int *matrix, unsigned int size) override {
        //idea is to rotate cycles inside the matrix

        const int cycleCount = size / 2;

#ifdef LOCAL_TEST
        dumpMatrix(matrix, size);
#endif

        for (int cycle = 0; cycle < cycleCount; cycle++) {
            int yStart = size / 2 - cycle - 1;
            int xStart = size / 2 - cycle - 1;
            int cycleSize = size % 2 + (cycle + 1) * 2;

            for (int pos = 0; pos < cycleSize - 1; pos++) {
                const int tmp = getByYX(matrix, size, yStart, xStart + pos);

                const int lastElementOffset = cycleSize - 1;
                setByYX(matrix, size, yStart, xStart + pos, getByYX(matrix, size, yStart + pos, xStart + lastElementOffset));
                setByYX(matrix, size, yStart + pos, xStart + lastElementOffset, getByYX(matrix, size, yStart + lastElementOffset, xStart + lastElementOffset - pos));
                setByYX(matrix, size, yStart + lastElementOffset, xStart + lastElementOffset - pos, getByYX(matrix, size, yStart + lastElementOffset - pos, xStart));
                setByYX(matrix, size, yStart + lastElementOffset - pos, xStart, tmp);
#ifdef LOCAL_TEST
                dumpMatrix(matrix, size);
#endif
            }
        }
#ifdef LOCAL_TEST
        dumpMatrix(matrix, size);
#elif
        dumpArray(matrix, size);
#endif
    }
};

int main()
{
#ifdef LOCAL_TEST
    auto fin = fstream("input.txt");
    cin.set_rdbuf(fin.rdbuf());
#endif

    unsigned int t;
    cin >> t;
    for (unsigned int i = 0; i < t; i++) {
        unsigned int matrixSize;
        cin >> matrixSize;

        const unsigned int elementCount = matrixSize * matrixSize;
        for (unsigned int j = 0; j < elementCount; j++) {
            cin >> matrix[j];
        }

        SolutionRotate r;
        r.solve(matrix, matrixSize);
    }
    return 0;
}