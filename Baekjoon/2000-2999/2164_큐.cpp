#include <iostream>
#include <queue>

using namespace std;

int solution(int n) {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    while(true) {
        if(q.size() == 1) {
            return q.front();
        }
        q.pop();
        if(q.size() == 1) {
            return q.front();
        }
        q.push(q.front());
        q.pop();
    }
}

int main() {
    int n;

    cin >> n;

    cout << solution(n);
    return 0;
}