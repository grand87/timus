#include<iostream>
#include<algorithm>

using namespace std;

void readArray(int* data, int size) {
    for(int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

int buf[50][50];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
	    int n;
	    cin >> n;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        if (n == 2) {
            cout << "1 1" << endl;
            continue;
        }

        buf[0][0] = 1;
        buf[1][0] = 1;
        buf[1][1] = 1;

        for (int line = 2; line < n; line++) {
            buf[line][0] = 1;
            buf[line][line] = 1;
            for (int cell = 1; cell < (line + 1) / 2 + 1; cell++) {
                buf[line][cell] = buf[line - 1][cell - 1] + buf[line - 1][cell];
                buf[line][line - cell] = buf[line][cell];
            }
        }
//        for(int j = 0; j < n; j++)
//            printArray(static_cast<int*>(buf[j]), j + 1);
        printArray(static_cast<int*>(buf[n - 1]), n);
	}
	return 0;
}