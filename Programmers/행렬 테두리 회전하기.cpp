#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

void initialize(int rows, int columns) {
    board.assign(rows, vector<int> (columns, 0));

    int num = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            board[i][j] = ++num;
        }
    }
}

int rotate(int x1, int y1, int x2, int y2) {
    int tmp = board[x1][y1];
    int answer = tmp;

    // y1열 위로 한 칸씩
    for(int i = x1+1; i <= x2; i++) {
        board[i-1][y1] = board[i][y1];
        answer = min(answer, board[i-1][y1]);
    }
    // x2행 왼쪽으로 한 칸씩
    for(int i = y1+1; i <= y2; i++) {
        board[x2][i-1] = board[x2][i];
        answer = min(answer, board[x2][i-1]);
    }
    // y2열 아래로 한 칸씩
    for(int i = x2-1; i >= x1; i--) {
        board[i+1][y2] = board[i][y2];
        answer = min(answer, board[i+1][y2]);
    }
    // x1행 오른쪽으로 한 칸씩
    for(int i = y2-1; i >= y1+1; i--) {
        board[x1][i+1] = board[x1][i];
        answer = min(answer, board[x1][i+1]);
    }
    // tmp 재배치
    board[x1][y1+1] = tmp;
    return answer;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    initialize(rows, columns);
    vector<int> answer;
    for(int i = 0; i < queries.size(); i++) {
        answer.push_back(rotate(queries[i][0]-1, queries[i][1]-1, queries[i][2]-1, queries[i][3]-1));
    }
    return answer;
}