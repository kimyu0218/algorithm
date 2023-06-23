#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int FRIENDS = 8;
int answer;
bool visited[FRIENDS]; // visited[i] = true : 누군가 i번째에 서있음
int pos[FRIENDS]; // pos[0] : A가 서있는 위치
map<char, int> id = {{'A', 0}, {'C', 1}, {'F', 2}, {'J', 3},
                     {'M', 4}, {'N', 5}, {'R', 6}, {'T', 7}};

bool satisfy(int n, vector<string> &data) { // 조건을 만족하는가
    for(int i = 0; i < n; i++) {
        int f1 = id[data[i][0]];
        int f2 = id[data[i][2]];
        int gap = data[i][4] - '0';
        int real_gap = abs(pos[f1] - pos[f2])-1;

        if(data[i][3] == '=' && real_gap != gap) {
            return false;
        }
        else if(data[i][3] == '<' && real_gap >= gap) {
            return false;
        }
        else if(data[i][3] == '>' && real_gap <= gap) {
            return false;
        }
    }
    return true;
}

void backtracking(int idx, int n, vector<string> &data) {
    if(idx == FRIENDS) { // 카카오프렌즈 배치 완료
        answer += satisfy(n, data);
        return;
    }
    for(int i = 0; i < FRIENDS; i++) { // i : 자리
        if(visited[i]) { // i번째 자리에 이미 누군가 서있음
            continue;
        }
        visited[i] = true; // i번째 자리 차있음
        pos[idx] = i; // idx가 i번째 자리 차지함
        backtracking(idx+1, n, data);
        visited[i] = false; // i번째 자리 비어있음
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    backtracking(0, n, data);
    return answer;
}