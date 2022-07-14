#include <iostream>
#include <queue>

using namespace std;

void delete_max(bool deleted[], priority_queue<pair<int, int>, vector<pair<int, int>>> &max) {
    while(!max.empty() && deleted[max.top().second]) max.pop();
}

void delete_min(bool deleted[], priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &min) {
    while(!min.empty() && deleted[min.top().second]) min.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, k, n;
    cin >> t; // 테스트 수

    char op;
    while(t--) {
        cin >> k; // 입력 데이터 수

        bool deleted[k];
        for(int i = 0; i < k; i++) deleted[i] = false;

        // (first : 값 / second : 인덱스)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min;
        priority_queue<pair<int, int>, vector<pair<int, int>>> max;
        for(int i = 0; i < k; i++) {
            cin >> op >> n;

            switch(op) {
                case 'D': // 1. DELETE
                    if(n == 1) { // 1-1. 최댓값 삭제
                        delete_max(deleted, max);
                        if(!max.empty()) {
                            deleted[max.top().second] = true; // pop 표기
                            max.pop();
                        }
                    }
                    else if(n == -1) { // 1-2. 최솟값 삭제
                        delete_min(deleted, min);
                        if(!min.empty()) {
                            deleted[min.top().second] = true; // pop 표기
                            min.pop();
                        }
                    }
                    break;
                case 'I': // 2. INSERT
                    min.push({n, i}); max.push({n, i});
                    break;
            }
        }
        delete_max(deleted, max);
        delete_min(deleted, min);
        if(max.empty()) cout << "EMPTY\n";
        else cout << max.top().first << ' ' << min.top().first << '\n';
    }
    return 0;
}