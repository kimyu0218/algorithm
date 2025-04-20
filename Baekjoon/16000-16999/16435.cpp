#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int l, vector<int> h) {
    int n = h.size();
    sort(h.begin(), h.end());

    for(int i = 0; i < n; i++) {
        if(h[i] > l) {
            break;
        }
        l++;
    }
    return l;
}

int main() {
    int n, l;
    vector<int> h;

    cin >> n >> l;

    h.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    cout << solution(l, h);
    return 0;
}