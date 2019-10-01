#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

long long arr[10000001] = {0};

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        unordered_map<long long, int> sumCount;

        int count = 0;
        long long sum = 0;
        sumCount[sum] = 1;

        for (int j = 0; j < n; j++) {
            sum += arr[j];
            if(sumCount.find(sum) != sumCount.end())
                count += sumCount[sum];
            sumCount[sum]++;
        }

        cout << count << endl;
    }
    return 0;
}