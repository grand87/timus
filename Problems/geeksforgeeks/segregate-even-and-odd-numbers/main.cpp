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

int buf[100000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
	    int n;
	    cin >> n;
	    
	    readArray(buf,n);
	    int oddIndex = n - 1;
	    while(buf[oddIndex] % 2 == 1 && oddIndex > 0)
	        oddIndex--;
        if(oddIndex == 0) {
            //all odd values in the right place
            sort(buf + oddIndex, buf + n);
            printArray(buf, n);
            continue;
        }

	    int evenIndex = 0;
	    
	    for(int j = 0; j < oddIndex; j++) {
	        if(buf[j] % 2 == 1) {
	            int tmp = buf[oddIndex];
	            buf[oddIndex] = buf[j];
	            buf[j] = tmp;
	            oddIndex--;
	            while(buf[oddIndex] % 2 == 1 && oddIndex > j)
	                oddIndex--;
	        }
	    }
        if (buf[oddIndex] % 2 == 0)
            oddIndex++;
	    sort(buf, buf + oddIndex);
	    sort(buf + oddIndex, buf + n);
	    printArray(buf, n);
	}
	return 0;
}