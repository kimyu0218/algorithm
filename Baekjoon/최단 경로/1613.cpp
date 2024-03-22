#include <iostream>
#include <vector>

using namespace std;

const int BEFORE = -1;
const int AFTER = 1;

vector<vector<int>> floyd_warshall(int n, vector<vector<int>> relation) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(relation[i][j]) {
                    continue;
                }
                if(relation[i][k] == BEFORE && relation[k][j] == BEFORE) {
                    relation[i][j] = BEFORE;
                    relation[j][i] = AFTER;
                }
                else if(relation[i][k] == AFTER && relation[k][j] == AFTER) {
                    relation[i][j] = AFTER;
                    relation[j][i] = BEFORE;
                }
            }
        }
    }
    return relation;
}

vector<vector<int>> solution(vector<vector<int>> relation) {
    int n = relation.size();
    return floyd_warshall(n, relation);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, s, before, after, s1, s2;
    vector<vector<int>> relation;

    cin >> n >> k;

    relation.assign(n, vector<int>(n, 0));
    while(k--) {
        cin >> before >> after;

        relation[before - 1][after - 1] = BEFORE;
        relation[after - 1][before - 1] = AFTER;
    }

    vector<vector<int>> result = solution(relation);

    cin >> s;

    while(s--) {
        cin >> s1 >> s2;
        cout << result[s1 - 1][s2 - 1] << '\n';
    }
    return 0;
}