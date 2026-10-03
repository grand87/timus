#include <iostream>
#include <cstdint>
//#include <map>
#include <vector>
//#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAX_K = 30000;
uint8_t callendar[MAX_K][MAX_K] = {};

const int HORIZONTAL_SCAN = 1 << 2;
const int VERTICAL_SCAN = 1 << 3;
const int BLACK = 1 << 4;

struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    /*freopen("output.txt", "wt", stdout);*/
#endif

    //set<pair<int, int>> blackPoints;
    unordered_set<pair<int, int>, pairhash> blackPoints;

    int m, n, k;
    cin >> n >> m >> k;

    for (int d = 0; d < k; d++) {
        int j, i;
        cin >> i >> j;
        blackPoints.insert(make_pair(i - 1, j - 1));
    }

    // FIXME: this approach does not work for the worst case (takes 30+ seconds)
    using Spans = unordered_map<pair<int, int>, int, pairhash>;

    // scan grid first horizontally to find only horizontal spans
    Spans horizontal;
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            // if it is not black - perform horizontal scan
            auto startPoint = make_pair(x, y);
            if (blackPoints.find(startPoint) != blackPoints.end()) {
                continue;
            }

            int endX = x;

            while (endX + 1 < n && blackPoints.find(make_pair(endX + 1, y)) == blackPoints.end()) {
                endX++;
            }
            
            // record span beginning at x,y and ending at endX
            horizontal[startPoint] = endX;
            
            // skip to the end of the span
            x = endX + 1;
        }
    }

    // scan vertically to find only vertical spans
    Spans vertical;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            // if it is not black - perform vertical scan
            auto startPoint = make_pair(x, y);
            if (blackPoints.find(startPoint) != blackPoints.end()) {
                continue;
            }

            int endY = y;

            while (endY + 1 < m && blackPoints.find(make_pair(x, endY + 1)) == blackPoints.end()) {
                // TODO: at this point the vertical span is larger than 1
                //  if current cell is part of horizonal span with length 1 - it should be removed from horizontal
                auto possibleHorizontalStart = horizontal.find(make_pair(x, endY));
                if (possibleHorizontalStart != horizontal.end() && possibleHorizontalStart->second == x) {
                    horizontal.erase(possibleHorizontalStart);
                }
                endY++;
            }

            if (y < endY) {
                auto possibleHorizontalStart = horizontal.find(make_pair(x, endY));
                if (possibleHorizontalStart != horizontal.end() && possibleHorizontalStart->second == x) {
                    continue;
                }

                // record vertical span beginning at x, y and ending at endY
                vertical[startPoint] = endY;
            }

            // skip to and span
            y = endY + 1;
        }
    }

    cout << horizontal.size() + vertical.size() << endl;
}