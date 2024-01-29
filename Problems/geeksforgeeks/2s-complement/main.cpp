#include<fstream>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

void binaryToString(int* buff, char* str, int size) {
    for (int i = 0; i < size; i++) {
        str[i] = '0' + buff[size - i - 1];
    }
    str[size] = 0;
}

int stringToBinary(const char* str, int* buff) {
    int pos = 0;

    const int strSize = strlen(str);

    while (str[pos]) {
        buff[strSize - pos - 1] = str[pos] - '0';
        ++pos;
    }
    return pos;
}

int incBinary(int* buff, int size) {
    int carry = 0;
    int v = 1;
    for (int i = 0; i < size; i++) {
        if (buff[i] + v + carry > 1) {
            carry = 1;
            buff[i] = 0;
        } else {
            buff[i] += carry + v;
            carry = 0;
        }
        v = 0;
    }
//    buff[size] = carry;
    return size;// +carry;
}

void invertBinary(int* buff, int size) {
    for (int i = 0; i < size; i++) {
        buff[i] = !buff[i];
    }
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t;
    cin >> t;

    const int MAX_STR_LEN = 10;

    char buf[MAX_STR_LEN + 2];
    int binary[MAX_STR_LEN + 1];

    for (int i = 0; i < t; i++) {
        cin >> buf;
        int len = stringToBinary(buf, binary);
        invertBinary(binary, len);
        len = incBinary(binary, len);
        binaryToString(binary, buf, len);
        cout << buf << endl;
    }
    return 0;
}