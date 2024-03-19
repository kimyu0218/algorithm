#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;

vector<string> v;
bool visited[MAX];
char ch[MAX - 1];

void backtracking(int idx, int k, int start, int end, string result) {
    if(idx == k + 1) {
        v.push_back(result);
        return;
    }

    for(int i = start; i < end; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        string new_result = result + to_string(i);
        if(ch[idx] == '<') {
            backtracking(idx + 1, k, i + 1, MAX, new_result);
        }
        else {
            backtracking(idx + 1, k, 0, i, new_result);
        }
        visited[i] = false;
    }
}

vector<string> solution(int k) {
    backtracking(0, k, 0, MAX, "");
    return { v[v.size() - 1], v[0]};
}

int main() {
    int k;

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> ch[i];
    }

    vector<string> answer = solution(k);

    cout << answer[0] << '\n' << answer[1];
    return 0;
}