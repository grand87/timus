#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int width, wall, start, end;
    
    cin >> width >> wall >> start >> end;

    int answer;
    if(start < end)
        answer = (end - start) * 2 * wall + (end - start - 1) * width;
    else
        answer = (start - end) * 2 * wall + (start - end + 1) * width;
    cout << answer;
}