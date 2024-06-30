#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    priority_queue<int> pq;

    cin >> n;

    while(n--) {
        cin >> x;

        pq.push(x);
    }

    while(!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}