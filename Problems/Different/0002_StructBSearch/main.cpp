#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>

#define LOCAL_TEST

using namespace std;

enum constants { MAX_RECORDS = 1000, MAX_DATA_SIZE = 300 };

struct Data {
    int b;  // secondary key
    int a;  // primary key
    char somedata[MAX_DATA_SIZE];
};

int cmdData(int akey, int bkey, const Data* pdata) {
    if (pdata->a != akey)
        return akey - pdata->a;

    if (pdata->b != bkey)
        return bkey - pdata->b;

    return 0;
}

int cmpBySecondaryKey(const Data* a, const Data* b) {
    if (a->a != b->a)
        return a->a - b->a;

    if (a->b != b->b)
        return a->b - b->b;

    return 0;
}

int my_bsearch(int akey, int bkey, Data* pdata, int num) {
    const Data* base = pdata;
    
    Data* pivot = 0;
    int result;

    while (num > 0) {
        const int pivotIndex = num >> 1;
        pivot = pdata + pivotIndex;
        result = cmdData(akey, bkey, pivot);

        if (result == 0)
            return pivot - base;

        if (result > 0) {
            pdata = pivot + 1;
            num--;
        }
        num >>= 1;
    }

    return -1;
}

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int testCases = 0;
    cin >> testCases;

    Data records[MAX_RECORDS];

    for (int t = 0; t < testCases; ++t) {
        int elements = 0;

        cin >> elements;
        for (int i = 0; i < elements; i++) {
            cin >> records[i].a;
            cin >> records[i].b;
            cin >> records[i].somedata;
        }

        // sort by some rule
        qsort(&records, elements, sizeof(Data), (int (*)(const void*, const void*))cmpBySecondaryKey);

        // process queries
        int queriesCount = 0;
        cin >> queriesCount;
        for (int i = 0; i < queriesCount; i++) {
            int a, b;
            char somedata[MAX_DATA_SIZE];
            cin >> a >> b >> somedata;

            int res = my_bsearch(a, b, records, elements);
            if (res != -1) {
                if (strcmp(somedata, records[res].somedata) != 0)
                    cout << "Error for query #" << i + 1 << " : " << somedata << endl;
            } else {
                if (strcmp(somedata, "none") != 0)
                    cout << "Error for query #" << i + 1 << " : " << somedata << endl;
            }
        }
    }

    return 0;
}