#include <iostream>
#include <string>

using namespace std;

int const DAYS_PER_YEAR[2][12] = {
    {
        31, //JAN
        28, //FEB
        31, //MAR
        30, //APR
        31, //MAY
        30, //JUN
        31, //JUL
        31, //AUG
        30, //SEP
        31, //OCT
        30, //NOV
        31  //DEC
    },
    {
        31, //JAN
        29, //FEB
        31, //MAR
        30, //APR
        31, //MAY
        30, //JUN
        31, //JUL
        31, //AUG
        30, //SEP
        31, //OCT
        30, //NOV
        31  //DEC
    }
};

string solve(int year) {
    // Complete this function

    bool isLeap = false;

    if (year < 1918) {
        isLeap = year % 4 == 0;
    }
    if (year >= 1918) {
        isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    //determine the month for the day X
    int x = 256;

    if (year == 1918)
    {
        x += 13;
    }

    int i = 0;
    int s = 0;
    while (i < 12 && s + DAYS_PER_YEAR[isLeap][i] <= x)
    {
        s += DAYS_PER_YEAR[isLeap][i++];
    }

    if (s == x)
        s = DAYS_PER_YEAR[isLeap][i - 1];
    else
    {
        ++i;
        s = x - s;
    }

    //now i is month

    string result;
    result.resize(10);
    result[2] = '.';
    result[5] = '.';
    
    //set day
    result[0] = '0' + s / 10;
    result[1] = '0' + s % 10;

    //set month
    result[3] = '0' + i / 10;
    result[4] = '0' + i % 10;

    //set year
    result[6] = '0' + year / 1000;
    result[7] = '0' + (year % 1000) / 100;
    result[8] = '0' + (year % 100) / 10;
    result[9] = '0' + (year % 10);

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
