#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, num;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(v.empty() || v.back() < num) {
            v.push_back(num);
        }
        else {
            auto iter = lower_bound(v.begin(), v.end(), num);
            *iter = num;
        }
    }

    cout << v.size();
    return 0;
}