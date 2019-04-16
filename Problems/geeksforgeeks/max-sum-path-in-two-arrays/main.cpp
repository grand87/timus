#include<iostream>
#include<algorithm>
#include<map>
#include<set>

using namespace std;
int max_path_sum(int[], int[], int, int);

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[1000], b[1000];
        for (int i = 0; i<N; i++)
            cin >> a[i];
        for (int i = 0; i<M; i++)
            cin >> b[i];
        int result = max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
int max_path_sum(int A[], int B[], int l1, int l2)
{
    //pre count sums on intervals between common values and select the appopriate interval while traversing the arrays
    set<int> pointsA;
    map<int, int> connections;

    const int* minArray = A[0] < B[0] ? A : B;
    const int minArraySize = A[0] < B[0] ? l1 : l2;
    
    int sumA = 0;
    for (int i = 0; i < minArraySize; i++) {
        sumA += minArray[i];       
        connections[minArray[i]] = sumA;
    }

    const int* maxArray = A[0] < B[0] ? B : A;
    const int maxArraySize = A[0] < B[0] ? l2 : l1;

    int sum = 0;
    int sumB = 0;
    int prevConnectionPoint = -1;

    for (int i = 0; i < maxArraySize; i++) {
        sumB += maxArray[i];

        if (i < maxArraySize - 1 && maxArray[i] == maxArray[i + 1]) {
            continue;
        }

        if (connections.find(maxArray[i]) != connections.end()) {
            //locate bridge width
            int bWidth = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (maxArray[j] == maxArray[i])
                    bWidth += maxArray[j];
                else
                    break;
            }
            
            //which distance to this point is greater so far?
            int alternateRouteSum = prevConnectionPoint == -1 ? connections[maxArray[i]] : sum + connections[maxArray[i]] - connections[prevConnectionPoint];
            sum = max(sumB, alternateRouteSum) - bWidth;
            sumB = sum;
            prevConnectionPoint = maxArray[i];
        }
    }

    sum = max(sumA, sumB);

    return sum;
}