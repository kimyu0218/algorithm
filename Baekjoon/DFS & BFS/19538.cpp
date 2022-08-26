#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> relation;

vector<int> bfs(int n, int m, vector<int> origin) {
    vector<int> result(n+1, -1);

    vector<int> rest(n+1, 0); // 루머를 믿어야 하는 주변인 수
    for(int i = 1; i <= n; i++)
        rest[i] = (relation[i].size() + 1) / 2; // (+1을 하는 이유 : 홀수/2인 경우 절반을 만족하지 않음)

    queue<int> q;
    // 최초 유포자 push
    for(int i = 0; i < m; i++) {
        result[origin[i]] = 0; // (최초 유포자는 루머를 0분부터 믿는다)
        q.push(origin[i]);
    }

    while(!q.empty()) {
        int p1 = q.front(); q.pop(); // 루머 유포자
        int time = result[p1]; // 루머 유포자가 루머를 믿은 시간

        // (p1이 p2에게 루머 전파)
        for(int i = 0; i < relation[p1].size(); i++) {
            int p2 = relation[p1][i]; // (p2 : p1의 주변인)
            if(result[p2] > -1) continue; // p2는 이미 루머를 믿음 -> p1이 전파시킬 수 없음

            rest[p2]--; // (p1이 루머 믿음)
            if(!rest[p2]) { // 루머 전파
                result[p2] = time + 1;
                q.push(p2);
            }
        }
    }
    return result;
}

int main() {
    int n, m, num;
    cin >> n;

    relation.assign(n+1, vector<int> (0, 0));
    for(int i = 1; i <= n; i++) { // i번째 사람의 주변인 입력
        while(true) {
            cin >> num;
            if(!num) break;
            relation[i].push_back(num);
        }
    }

    cin >> m;
    vector<int> origin(m, 0); // 최초 유포자 저장
    for(int i = 0; i < m; i++)  // 최초 유포자 입력
        cin >> origin[i];

    vector<int> result = bfs(n, m, origin);
    for(int i = 1; i <= n; i++)
        cout << result[i] << ' ';
    return 0;
}