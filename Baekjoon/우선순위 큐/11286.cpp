#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, x;
    priority_queue<pi, vector<pi>, greater<>> pq;

    cin >> n;

    while(n--) {
        cin >> x;

        if(x != 0) {
            pq.push({ abs(x), x });
            continue;
        }
        if(pq.empty()) {
            cout << 0 << '\n';
            continue;
        }
        cout << pq.top().second << '\n';
        pq.pop();
    }
    return 0;
}