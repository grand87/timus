#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'solve' function below.
*
* The function is expected to return an int64_t EGER_ARRAY.
* The function accepts following parameters:
*  1. int64_t EGER n
*  2. int64_t EGER m
*  3. int64_t EGER_ARRAY h
*  4. 2D_int64_t EGER_ARRAY rounds
*/

int64_t  getMaxHeight(int64_t  l, int64_t  r, const vector<int64_t >& h) {
    int64_t curmax = h[l];
    for (int64_t  i = l + 1; i <= r; i++)
        curmax = max(curmax, h[i]);
    return curmax;
}

int64_t  getSetPower(const vector<int64_t >& selfPowers, const vector<int64_t >& selfPowersSum, const vector<int64_t >& setPowers, const vector<int64_t >& h, int64_t  l, int64_t  r) {
    if (l == r)
        return selfPowers[l];

    if (l == 0)
        return setPowers[r];

    return setPowers[r] - setPowers[l] - selfPowersSum[l] - l * h[r];
}

vector<int64_t > solve(int64_t  n, int64_t  m, vector<int64_t > h, vector<vector<int64_t >> rounds) {
    //prebuild table of powers for n players
    vector<int64_t > selfPowers(n);
    vector<int64_t > selfPowersSum(n);
    vector<int64_t > setPowers(n);
    vector<int64_t > maxHeight(n);
    

    selfPowers[0] = 2 * h[0];
    selfPowersSum[0] = 2 * h[0];
    setPowers[0] = selfPowersSum[0];
    maxHeight[0] = h[0];
    int64_t selfPowerSum = 2 * h[0];


    for (int64_t  i = 1; i < n; i++) {
        selfPowers[i] = h[i] * 2;
        selfPowersSum[i] = selfPowersSum[i - 1] + selfPowers[i];
        setPowers[i] = setPowers[i - 1] + selfPowersSum[i] + i * selfPowers[i];
        maxHeight[i] = max(h[i], maxHeight[i - 1]);
    }

    vector<int64_t > result (m);
    for (int64_t  i = 0; i < m; i++) {
        const int64_t  maxPower = rounds[i][2];
        //calculate K for round - the answer is the smalles height of a player in the set of players for which the power is minimal and > then maxPower

        result[i] = -1;
        int64_t  l = rounds[i][0] - 1;
        int64_t  r = l;

        while (l <= r && r < rounds[i][1]) {
            int64_t  setPower = getSetPower(selfPowers, selfPowersSum, setPowers, h, l, r);
            if(setPower >= maxPower) {
                if (result[i] == -1) {
                    result[i] = getMaxHeight(l, r, h);
                } else {
                    result[i] = min(getMaxHeight(l, r, h), result[i]);
                }
                l++;
            }
            else
                r++;

            if (l > r)
                r++;
        }
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    ostream& fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int64_t  n = stoi(first_multiple_input[0]);

    int64_t  m = stoi(first_multiple_input[1]);

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int64_t > h(n);

    for (int64_t  i = 0; i < n; i++) {
        int64_t  h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    vector<vector<int64_t >> rounds(m);

    for (int64_t  i = 0; i < m; i++) {
        rounds[i].resize(3);

        string rounds_row_temp_temp;
        getline(cin, rounds_row_temp_temp);

        vector<string> rounds_row_temp = split(rtrim(rounds_row_temp_temp));

        for (int64_t  j = 0; j < 3; j++) {
            int64_t  rounds_row_item = stoull(rounds_row_temp[j]);

            rounds[i][j] = rounds_row_item;
        }
    }

    vector<int64_t > answer = solve(n, m, h, rounds);

    for (int64_t  i = 0; i < answer.size(); i++) {
        fout << answer[i];

        if (i != answer.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

#ifdef ONLINE_JUDGE
    fout.close();
#endif

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int , int >(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int , int >(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}