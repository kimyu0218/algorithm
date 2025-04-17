#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

set<int> get_gap(int n, vector<int> pos) {
    set<int> gaps;

    for(int i = 0; i < n - 1; i++) {
        gaps.insert(pos[i + 1] - pos[i]);
    }
    return gaps;
}

int solution(vector<int> pos) {
    int n = pos.size();
    if(n == 2) {
        return 0;
    }

    int range = pos[n - 1] - pos[0];
    int g = range;

    set<int> gaps = get_gap(n, pos);
    for(auto iter = gaps.begin(); iter != gaps.end(); iter++) {
        int tmp = gcd(min(*iter, g), max(*iter, g));
        g = min(g, tmp);
    }
    return range / g - (n - 1);
}

int main() {
    int n;
    vector<int> pos;

    cin >> n;

    pos.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    cout << solution(pos);
    return 0;
}