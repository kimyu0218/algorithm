#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num) {
    sort(num.begin(), num.end());
    return num;
}

int main() {
    int n;
    vector<int> num;

    cin >> n;

    num.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<int> sorted = solution(num);
    for(int i = 0; i < n; i++) {
        cout << sorted[i] << '\n';
    }
    return 0;
}