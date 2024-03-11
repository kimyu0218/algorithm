#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

string lastDirectory(int n, string path) { // path에서 가장 하위 디렉토리 찾기
    for(int i = n-1; i >= 0; i--) {
        if(path[i] == '/') {
            return path.substr(i+1, n-i);
        }
    }
    return path;
}

pi solution(string path, map<string, int> &dir, vector<vector<pi>> &tree) {
    int type = 0, cnt = 0;
    queue<int> q; // 디렉토리 저장하는 큐

    string d_name = lastDirectory(path.length(), path);
    map<int, int> m; // 파일 종류 저장
    q.push(dir[d_name]); // 디렉토리 push

    while(!q.empty()) {
        int d_num = q.front();
        q.pop();

        for(int i = 0; i < tree[d_num].size(); i++) {
            int c = tree[d_num][i].second; // 폴더/파일 여부
            if(c) { // 1. 폴더인 경우, 해당 폴더의 하위 파일 탐색 필요
                q.push(tree[d_num][i].first);
            }
            else { // 2. 파일인 경우, 개수 세기
                m[tree[d_num][i].first]++;
                cnt++;
            }
        }
    }
    type = m.size();
    return {type, cnt}; // 파일 종류/개수 리턴
}

int main() {
    int n, m, c, q, d_idx = 0, f_idx = 0;
    string p, f, path;
    map<string, int> dir; // 디렉토리
    map<string, int> file; // 파일
    vector<vector<pi>> tree;

    cin >> n >> m;
    tree.assign(n+1, vector<pi> {});

    for(int i = 0; i < n+m; i++) { // 폴더/파일 정보 입력
        cin >> p >> f >> c;

        int parent, child;
        if(p != "main" && dir[p] == 0) { // 1. 최상위 디렉토리인가 아니면서 dir[p]가 0인 경우
            // dir["main"]이 항상 0값을 가져야 하므로 새로운 값으로 할당
            dir[p] = ++d_idx;
        }
        parent = dir[p];
        if(c) { // 2. child가 폴더인 경우
            if(dir[f] == 0) {
                dir[f] = ++d_idx;
            }
            child = dir[f];
        }
        else { // 3. child가 파일인 경우
            if(file[f] == 0) {
                file[f] = ++f_idx;
            }
            child = file[f];
        }
        tree[parent].push_back({child, c});
    }

    cin >> q;
    while(q--) { // 쿼리 입력
        cin >> path;
        pi ans = solution(path, dir, tree);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}