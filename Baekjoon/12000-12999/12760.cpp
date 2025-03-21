#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<int> game(int n, vector<priority_queue<int>> &pq) {
    vector<int> winners = {0};

    int largest = pq[0].top();
    pq[0].pop();

    for(int i = 1; i < n; i++) {
        int top = pq[i].top();
        pq[i].pop();

        if(top > largest) {
            largest = top;
            winners = {i};
        }
        else if(top == largest) {
            winners.push_back(i);
        }
    }
    return winners;
}

vector<int> find_winner(int n, vector<int> scores) {
    vector<int> winners = {1};
    int largest = scores[0];

    for(int i = 1; i < n; i++) {
        if (scores[i] > largest) {
            largest = scores[i];
            winners = {i + 1};
        }
        else if(scores[i] == largest) {
            winners.push_back(i + 1);
        }
    }
    return winners;
}

vector<int> solution(vector<vector<int>> cards) {
    int n = cards.size();
    int m = cards[0].size();

    vector<int> scores (n, 0);
    vector<priority_queue<int>> pq (n, priority_queue<int>());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            pq[i].push(cards[i][j]);
        }
    }

    while(m--) {
        vector<int> winners = game(n, pq);
        for(int i = 0; i < winners.size(); i++) {
            scores[winners[i]]++;
        }
    }

    return find_winner(n, scores);
}

int main() {
    int n, m;
    vector<vector<int>> cards;

    cin >> n >> m;

    cards.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cards[i][j];
        }
    }

    vector<int> answer = solution(cards);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}