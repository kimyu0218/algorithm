#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, a;
    priority_queue<int> pq;

    cin >> n >> k;

    while(n--) {
        cin >> a;

        pq.push(a);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    cout << pq.top();
    return 0;
}