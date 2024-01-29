#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

bool isMagicSquare(const vector<int>& combination, int size) {
    // row 0
    int s = 0;
    for (int j = 0; j < size; j++)
        s += combination[j];

    // other rows
    for (int j = 1; j < size; j++) {
        int rowSum = 0;
        int offset = j * size;
        for (int i = 0; i < size; i++) {
            rowSum += combination[offset + i];
        }
        if (rowSum != s)
            return false;
    }

    // columns
    for (int j = 0; j < size; j++) {
        int colSum = 0;
        for (int i = 0; i < size; i++) {
            colSum += combination[j + size * i];
        }
        if (colSum != s)
            return false;
    }

    // diagonal 1
    int d1Sum = 0;
    for (int j = 0; j < size; j++) {
        d1Sum += combination[size * j + j];
    }
    if (d1Sum != s)
        return false;

    // diagonal 2
    int d2Sum = 0;
    for (int j = 0; j < size; j++) {
        d2Sum += combination[size * (size - j - 1) + j];
    }
    if (d2Sum != s)
        return false;

#ifdef LOCAL_TEST
    static int combId = 0;
    combId++;
    cout << combId << " : ";
    printVector(cout, combination);
    cout << endl;
#endif

    return true;
}

void generateHelper(vector<int> original, int size, vector<vector<int>>& results, int index) {
    if (index == original.size()) {
        if (isMagicSquare(original, size))
            results.push_back(original);
    } else {
        for (size_t i = index; i < original.size(); ++i) {
            swap(original[index], original[i]);
            generateHelper(original, size, results, index + 1);
            swap(original[index], original[i]);
        }
    }
}

void generate(vector<int> original, int size, vector<vector<int>>& results) {
    vector<int> combination(original.size());
    generateHelper(original, size, results, 0);
}

vector<vector<int>> generateMagicSquares(int dimension) {
    const int size = dimension * dimension;
    vector<int> square(size);
    for (int i = 0; i < size; ++i) {
        square[i] = i + 1;
    }

    vector<vector<int>> results;
    // generate all permutations
    generate(square, dimension, results);
    return results;
}

int findDiff(const vector<int>& magic, const vector<int>& original) {
    int diff = 0;
    for (size_t i = 0; i < magic.size(); i++)
        diff += abs(original[i] - magic[i]);

#ifdef LOCAL_TEST
    cout << "\nFind diff = " << diff << endl;
    printVector(cout, magic);
    cout << endl;
    printVector(cout, original);
#endif

    return diff;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<int> original;
    for (size_t r = 0; r < s.size(); r++)
        for (size_t c = 0; c < s.size(); c++) {
            original.push_back(s[r][c]);
        }

    if (isMagicSquare(original, s.size()))
        return 0;

    // generate magic squares
    const vector<vector<int>> magicCombs = generateMagicSquares(s.size());

    int dist = 100000;
    for (const auto& c : magicCombs) {
        dist = min(dist, findDiff(c, original));
    }

    return dist;
}

int main() {
#ifndef LOCAL_TEST
    ofstream fout(getenv("OUTPUT_PATH"));
#else
    ostream& fout = cout;
    fstream data("input.txt");
    cin.set_rdbuf(data.rdbuf());
#endif

    int tCount = 0;
    cin >> tCount;

    assert(isMagicSquare(vector<int>({8, 1, 6, 3, 5, 7, 4, 9, 2}), 3) == true);
    assert(isMagicSquare(vector<int>({5, 9, 1, 7, 2, 6, 3, 4, 8}), 3) == false);

    for (int t = 0; t < tCount; ++t) {
        vector<vector<int>> s(3);
        for (int i = 0; i < 3; i++) {
            s[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> s[i][j];
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = formingMagicSquare(s);
        fout << result << "\n";
    }
#ifndef LOCAL_TEST
    fout.close();
#endif
    return 0;
}
