#include <fstream>
#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

constexpr pair<int, int> directions[] = {
    {0, 1},   // right
    {1, 0},   // down
    {0, -1},  // left
    {-1, 0}   // up
};

int getNextDirectoin(int direction) {
    return (direction + 1) % 4;
}

void makeMove(pair<int, int>& location, int direction) {
    location.first += directions[direction].first;
    location.second += directions[direction].second;
}

void makeMoveBack(pair<int, int>& location, int direction) {
    location.first -= directions[direction].first;
    location.second -= directions[direction].second;
}

bool isValid(const pair<int, int>& position, int rows, int columns) {
    return position.first >= 0 && position.first < rows && position.second >= 0 && position.second < columns;
}

pair<int, int> findExit(vector<vector<int>>& matrix, int rows, int columns) {
    int direction = 0;
    pair<int, int> position{0, 0};

    while (isValid(position, rows, columns)) {
        if (matrix[position.first][position.second] == 1) {
            matrix[position.first][position.second] = 0;
            direction = getNextDirectoin(direction);
        } else
            makeMove(position, direction);
    }

    makeMoveBack(position, direction);

    return position;
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int rows, columns = 0;
        cin >> rows >> columns;

        vector<vector<int>> matrix;
        readMatrix(columns, rows, matrix);

        auto result = findExit(matrix, rows, columns);

        cout << result.first << " " << result.second << endl;
    }

    return 0;
}