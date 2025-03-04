#include <iostream>
#include <queue>

using namespace std;

queue<int> josephus(int n, int k) {
    queue<int> q, ans;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    int cnt = 0;
    while(!q.empty()) {
        cnt++;
        if(cnt == k) {
            ans.push(q.front());
            cnt = 0;
        }
        else {
            q.push(q.front());
        }
        q.pop();
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> ans = josephus(n, k);
    cout << "<" << ans.front();
    ans.pop();

    while(!ans.empty()) {
        cout << ", " << ans.front();
        ans.pop();
    }
    cout << ">";
    return 0;
}