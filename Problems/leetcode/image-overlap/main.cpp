#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void readMatrix(vector<vector<int>> &matrix, int n) {
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void dumpMatrix(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {

    vector<vector<int>> getIntegralImage(const vector<vector<int>>& img, int &maxSum, int &maxX, int &maxY) {
        const int n = img.size();
        vector<vector<int>> res = img;

        maxSum = img[0][0];
        maxX = 0;
        maxY = 0;

        //top edge
        for (int x = 1; x < n; x++) {
            res[0][x] += res[0][x - 1];
            if (res[0][x] > maxSum) {
                maxSum = res[0][x];
                maxX = x;
            }
        }
        //left edge
        for (int y = 1; y < n; y++) {
            res[y][0] += res[y - 1][0];
            if (res[y][0] > maxSum) {
                maxSum = res[y][0];
                maxX = 0;
                maxY = y;
            }
        }

        for (int y = 1; y < n; y++) {
            for (int x = 1; x < n; x++) {
                res[y][x] += res[y - 1][x] + res[y][x - 1] - res[y - 1][x - 1];
                if (res[y][x] > maxSum) {
                    maxSum = res[y][x];
                    maxX = x;
                    maxY = y;
                }
            }
        }
        return res;
    }

    vector<pair<int,int>> locateRect(const vector<vector<int>>& img, int sum) {
        const int n = img.size();
        vector<pair<int, int>> res;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (img[y][x] >= sum) {
                    res.push_back(make_pair(x, y));
                }
            }
        }
        return res;
    }

    void locateRectLeftTop(const vector<vector<int>>& img, int &maxX, int &maxY) {
        const int n = img.size();
        maxX = 0;
        maxY = 0;

        for (int y = 0; y < n; y++) {
            if (img[y][n - 1] > 0) {
                maxY = y;
                break;
            }
        }

        for (int x = 0; x < n; x++) {
            if (img[n-1][x] > 0) {
                maxX = x;
                break;
            }
        }
    }

public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        //generate integral images for A & B
        int maxA, maxAx, maxAy;
        vector<vector<int>> intA = getIntegralImage(A, maxA, maxAx, maxAy);
        int maxB, maxBx, maxBy;
        vector<vector<int>> intB = getIntegralImage(B, maxB, maxBx, maxBy);

        dumpMatrix(intA);
        cout << endl;
        dumpMatrix(intB);

        //locate the rect where A & B has most common data
        if (maxA < maxB) {
            maxB = maxA;
        }
        else if (maxA > maxB) {
            maxA = maxB;
        }

        //locate the bottom right corners
        vector<pair<int, int>> brA = locateRect(intA, maxA);
        vector<pair<int, int>> brB = locateRect(intB, maxA);


        //two right bottom corners are (maxAx, maxAy) & (maxBx, maxBy)
        //locate the top left corners - places where 1-s start
        int minAx, minAy;
        locateRectLeftTop(intA, minAx, minAy);
        int minBx, minBy;
        locateRectLeftTop(intB, minBx, minBy);

        //check how many cell has valid values in 2 rectangels (maxAx - rectW, maxAy - rectH)-(maxAx,maxAy) & (maxBx - rectW, maxBy - rectH)-(maxBx,maxBy)  
        int maxCount = 0;

        for (int rectA = 0; rectA < brA.size(); rectA++)
        {
            for (int rectB = 0; rectB < brB.size(); rectB++) {
                maxAx = brA[rectA].first;
                maxAy = brA[rectA].second;

                maxBx = brB[rectB].first;
                maxBy = brB[rectB].second;

                //locate the intersection rect
                //const int rectW = min(maxAx - minAx, maxBx - minBx) + 1;
                //const int rectH = min(maxAy - minAy, maxBy - minBy) + 1;

                const int rectW = min(maxAx, maxBx) + 1;
                const int rectH = min(maxAy, maxBy) + 1;

                if (maxAx > maxBx || maxAy > maxBy) {
                    const int maxOffsetX = maxAx - maxBx;
                    const int maxOffsetY = maxAy - maxBy;
                    for (int offsetY = 0; offsetY <= maxOffsetY; offsetY++) {
                        for (int offsetX = 0; offsetX <= maxOffsetX; offsetX++) {
                            int count = 0;
                            for (int y = 0; y < rectH; y++)
                                for (int x = 0; x < rectW; x++) {
                                    const int cellA = A[maxAy - y - offsetY][maxAx - x - offsetX];
                                    const int cellB = B[maxBy - y][maxBx - x];
                                    count += (cellA == 1 && cellB == 1);
                                }
                            maxCount = max(count, maxCount);
                        }
                    }
                }

                if (maxAx < maxBx || maxAy < maxBy) {
                    const int maxOffsetX = maxBx - maxAx;
                    const int maxOffsetY = maxBy - maxAy;

                    for (int offsetY = 0; offsetY <= maxOffsetY; offsetY++) {
                        for (int offsetX = 0; offsetX <= maxOffsetX; offsetX++) {
                            int count = 0;
                            for (int y = 0; y < rectH; y++)
                                for (int x = 0; x < rectW; x++) {
                                    const int cellA = A[maxAy - y][maxAx - x];
                                    const int cellB = B[maxBy - y - offsetY][maxBx - x - offsetX];
                                    count += (cellA == 1 && cellB == 1);
                                }
                            maxCount = max(count, maxCount);
                        }
                    }
                }
            }
        }

        return maxCount;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int n;
        cin >> n;

        vector<vector<int>> imgA;
        readMatrix(imgA, n);

        vector<vector<int>> imgB;
        readMatrix(imgB, n);

        Solution s;
        cout << s.largestOverlap(imgA, imgB) << endl;
    }
}