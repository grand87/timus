#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class A0Paper {
public:
    static const string strAnswer[2];

    string canBuild(const vector<long long int>& sheets) {

        //we start from 1 due to we need 1 A0 to form A0
        long long int sheetsRequired = 1;
        
        for (size_t sheetType = 0; sheetType < sheets.size(); sheetType++) {
            sheetsRequired -= sheets[sheetType];

            if (sheetsRequired <= 0) {
                //we formed the A0
                break;
            }
            
            sheetsRequired *= 2;
        }
        
        return strAnswer[sheetsRequired <= 0];
    }
};

const string A0Paper::strAnswer[] = {"Impossible", "Possible"};

int main() {
#ifdef LOCAL_TEST
    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    unsigned int t = 0;
    cin >> t;

    A0Paper solver;

    unsigned int correctResults = 0;

    for (unsigned int i = 0; i < t; i++) {
        unsigned typesCount = 0;
        cin >> typesCount;

        vector<long long int> sheets(typesCount);
        readVector(cin, sheets, typesCount);
        auto readAnswer = []() -> bool {
            bool res;
            cin >> res;
            return res;
        };
        const bool correctAnswer = readAnswer();

        const bool isCorrect = solver.canBuild(sheets).compare(A0Paper::strAnswer[correctAnswer]) == 0;
        correctResults += isCorrect;
        cout << isCorrect << endl;
    }

    if (correctResults == t)
        cout << "Passed\n";
    else
        cout << "Failed\n";

    return 0;
}