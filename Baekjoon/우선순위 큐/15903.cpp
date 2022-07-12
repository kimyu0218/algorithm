#include <iostream>
#include <queue>

using namespace std;

void card_game(int m, priority_queue<long long, vector<long long>, greater<>> &pq) { // 카드 합체 놀이
    long long x, y, sum = 0;
    while (m--) { // 합체 놀이
        // 1. 두 장에 쓰여진 수를 더한다
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        sum = x + y;
        // 2. 계산한 값을 두 장에 덮여쓴다
        pq.push(sum);
        pq.push(sum);
    }
}

long long game_score(priority_queue<long long, vector<long long>, greater<>> pq) { // 게임 점수 계산
    long long sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int main() {
    int n, m, x;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<>> card;
    for(int i = 0; i < n; i++) {
        cin >> x;
        card.push(x);
    }

    card_game(m, card);
    cout << game_score(card);
    return 0;
}