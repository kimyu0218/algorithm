#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    priority_queue<int> pq;

    cin >> n;
    while(n--) {
        cin >> x;

        if(x != 0) {
            pq.push(x);
            continue;
        }
        if(pq.empty()) {
            cout << 0 << '\n';
            continue;
        }
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}