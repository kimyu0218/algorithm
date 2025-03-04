#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solution(vector<int> a, int b, int c) {
    ll result = 0;
    for(int i = 0; i < a.size(); i++) {
        result++;

        int remain = a[i] - b;
        if(remain <= 0) {
            continue;
        }
        result += (remain / c) + (remain % c != 0);
    }
    return result;
}

int main() {
    int n, b, c;
    vector<int> a;

    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> b >> c;

    cout << solution(a, b, c);
    return 0;
}