#include <iostream>

using namespace std;

const int N = 10, MAX = 1000000;
int n, start_pos;
int result = N * N * MAX + 1;
bool check[N+1] = { false, }; // 순회 여부 저장하는 배열
int way[N+1][N+1]; // 비용 정보 저장하는 배열

void backtracking(int prev, int cnt, int weight) {
    if(cnt == n) { // n개 도시 순회 완료
        if(way[prev][start_pos] == 0) return; // 이동할 수 없는 경우 pass
        weight += way[prev][start_pos]; // 원점으로 돌아오기
        result = min(result, weight); return;
    }
    for(int i = 0; i < n; i++) {
        if(check[i] || way[prev][i] == 0) continue; // 방문한 도시나 이동할 수 없는 경우 pass
        check[i] = true;
        backtracking(i, cnt+1, weight + way[prev][i]);
        check[i] = false;
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> way[i][j];
    }

    for(int i = 0; i < n; i++) {
        start_pos = i; check[i] = true; // 시작점 방문 완료
        backtracking(i, 1, 0);
        check[i] = false;
    }
    cout << result;
    return 0;
}