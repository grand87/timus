#include <iostream>
#include <algorithm>

using namespace std;

constexpr int cMaxSize = 55000;

struct listData {
    int values[cMaxSize];
    size_t size;
    int minValue;
    int maxValue;
};

listData values[2];

size_t readList(listData *list) {
    cin >> list->size;
    for (size_t i = 0; i < list->size; ++i) {
        cin >> list->values[i];
        if (i == 0) {
            list->minValue = list->values[0];
            list->maxValue = list->values[0];
        }
        else {
            if (list->values[i] < list->minValue) {
                list->minValue = list->values[i];
            } else if (list->values[i] > list->maxValue) {
                list->maxValue = list->values[i];
            }
        }
    }
    return list->size;
}

bool findValue(listData* list, int value) {
    if (list->minValue > value || list->maxValue < value)
        return false;
    for (size_t i = 0; i < list->size; ++i) {
        if (list->values[i] == value)
            return true;
    }
    return false;
}

bool descComp(int i, int j) { return (i > j); }

bool findValue2(listData* list, int value, bool isSortedAsc) {
    if(isSortedAsc)
        return binary_search(list->values, list->values + list->size, value);
    return binary_search(list->values, list->values + list->size, value, descComp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    readList(&values[0]);
    readList(&values[1]);

    if (values[0].size > values[1].size) {
        for (size_t i = 0; i < values[1].size; ++i) {
            const int valueToLocate = 10000 - values[1].values[i];
            if (findValue2(&values[0], valueToLocate, true)) {
                cout << "YES\n";
                return 0;
            }
        }
    } else {
        for (size_t i = 0; i < values[0].size; ++i) {
            const int valueToLocate = 10000 - values[0].values[i];
            if (findValue2(&values[1], valueToLocate, false)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}