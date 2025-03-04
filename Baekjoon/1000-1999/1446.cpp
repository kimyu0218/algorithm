#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct road {
    int s, e, d;
};

bool cmp(road &r1, road &r2) {
    if(r1.s != r2.s) {
        return r1.s < r2.s;
    } 
    if(r1.e != r2.e) {
        return r1.e < r2.e;
    }
    return r1.d < r2.d;
}

int solution(int d, vector<road> shortcut) {
    int n = shortcut.size();
    vector<int> dp (d + 1, 0);
    
    sort(shortcut.begin(), shortcut.end(), cmp);
    
    for(int i = 0; i <= d; i++) {
        dp[i] = i;
    }
    for(int i = 0; i < n; i++) {
        int s = shortcut[i].s;
        int e = shortcut[i].e;
        int dist = shortcut[i].d;
        
        if(e > d) {
            continue;
        }
        dp[e] = min(dp[e], dp[s] + dist);
        for(int j = e + 1; j <= d; j++) {
            dp[j] = min(dp[j], dp[e] + j - e);
        }
    }
    return dp[d];
}

int main() {
    int n, d;
    vector<road> shortcut;
    
    cin >> n >> d;
    
    shortcut.assign(n, {0, 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> shortcut[i].s >> shortcut[i].e >> shortcut[i].d;
    }
    
    cout << solution(d, shortcut);
    return 0;
}