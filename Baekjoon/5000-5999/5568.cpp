#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int TOTAL_CNT = 10;
const int SELECT_CNT = 4;

set<int> s;

bool visited[TOTAL_CNT];
int num[SELECT_CNT];

void backtracking(int idx, int k, int n, vector<int> cards) {
    if(idx == k) {
        string num_str = "";
        for(int i = 0; i < k; i++) {
            num_str += to_string(num[i]);
        }
        s.insert(stoi(num_str));
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        num[idx] = cards[i];
        backtracking(idx + 1, k, n, cards);
        visited[i] = false;
    }
}

int solution(int k, vector<int> cards) {
    int n = cards.size();
    backtracking(0, k, n, cards);
    return s.size();
}

int main() {
    int n, k;
    vector<int> cards;

    cin >> n >> k;

    cards.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    cout << solution(k, cards);
    return 0;
}