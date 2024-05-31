#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

pi solution(vector<vector<char>> room) {
    pi answer = {0, 0};
    int n = room.size();

    for(int i = 0; i < n; i++) {
        int len = room[i][0] == '.' ? 1 : 0;

        for(int j = 1; j < n; j++) {
            if(room[i][j] == '.') {
                len++;
                continue;
            }
            answer.first += (len >= 2);
            len = 0;
        }
        answer.first += (len >= 2);
    }

    for(int i = 0; i < n; i++) {
        int len = room[0][i] == '.' ? 1 : 0;

        for(int j = 1; j < n; j++) {
            if(room[j][i] == '.') {
                len++;
                continue;
            }
            answer.second += (len >= 2);
            len = 0;
        }
        answer.second += (len >= 2);
    }
    return answer;
}

int main() {
    int n;
    string input;
    vector<vector<char>> room;

    cin >> n;

    room.assign(n, vector<char> (n, '\0'));
    for(int i = 0; i < n; i++) {
        cin >> input;

        for(int j = 0; j < n; j++) {
            room[i][j] = input[j];
        }
    }

    pi answer = solution(room);
    cout << answer.first << ' ' << answer.second;
    return 0;
}