#include<iostream>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

int table[6][10];

const int decPows[] = { 1, 10,100,1000,10000,100000,1000000 };

void precalculateTable() {
    for (int i = 0; i < 10; i++)
        table[0][i] = i >= 4;

    for (int j = 1; j < 6; j++)
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                table[j][i] = table[j - 1][9];
            } else if (i == 4) {
                table[j][i] = decPows[j] + table[j][i - 1];
            } else {
                table[j][i] = table[j][i - 1] + table[j - 1][9];
            }
        }
}

int countPower10(int v) {
    v = v / 10;
    int r = 0;
    while (v > 0) {
        r++;
        v /= 10;
    }
    return r;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;

    precalculateTable();

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int count = 0;
        int powerOf10 = countPower10(n);

        while (powerOf10 >= 0) {
            const int row = n / decPows[powerOf10];
            //is major number == 4
            if (row == 4) {
                if (powerOf10 > 0) {
                    count += table[powerOf10][row - 1];
                    count += n % decPows[powerOf10];
                    count += 1;
                } else
                    count += table[powerOf10][row];
                break;
            } else {
                if (row != 0)
                    count += table[powerOf10][row - 1];
                else
                    count += table[powerOf10][row];
            }
            n %= decPows[powerOf10];
            if (powerOf10 == 0)
                break;
            powerOf10 = countPower10(n);
        }
        cout << count << endl;
    }
    return 0;
}