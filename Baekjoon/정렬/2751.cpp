#include <iostream>
#include <vector>
#include <algorithm> // algorithm의 sort 알고리즘 이용

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    arr.assign(n, 0);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end()); // 오름차순 정렬

    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}