#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> p) {
    int result = 0;
    sort(p.begin(), p.end());

    int waiting = 0;
    for(int i = 0; i < p.size(); i++) {
        result += waiting + p[i];
        waiting += p[i];
    }
    return result;
}

int main() {
    int n;
    vector<int> p;

    cin >> n;

    p.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solution(p);
    return 0;
}