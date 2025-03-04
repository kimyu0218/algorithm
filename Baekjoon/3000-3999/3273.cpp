#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int two_pointer(int x, int n, vector<int> a) {
    int cnt = 0;
    int left = 0, right = n-1;
    while(left < right) {
        int sum = a[left] + a[right];
        if(sum == x) cnt++; // (a[i], a[j])쌍 발견

        if(sum >= x) right--;
        else left++;
    }
    return cnt;
}

int main() {
    int n, x;
    cin >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end()); // 오름차순

    cin >> x;
    cout << two_pointer(x, n, a);
    return 0;
}