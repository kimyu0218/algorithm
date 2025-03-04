#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e6 * 4;
int n;
vector<vector<int>> a;

int cntPop(int sr, int er, int sc, int ec, int num, vector<vector<int>> &region) { // num 구역 인구 세기
    int cnt = 0;
    for(int r = sr; r < er; r++) {
        for(int c = sc; c < ec; c++) {
            if(region[r][c] && region[r][c] != num) {
                continue;
            }
            region[r][c] = num;
            cnt += a[r][c];
        }
    }
    return cnt;
}

int cntPop5(int x, int y, int d1, int d2, vector<vector<int>> &region) { // 5구역 인구 세기
    int cnt = 0;

    // 1. 경계선 만들기
    for(int i = 0; i <= d1; i++) { // 1번 & 4번 경계선
        region[x+i][y-i] = 5;
        region[x+d2+i][y+d2-i] = 5;
    }
    for(int i = 0; i <= d2; i++) { // 2변 & 3번 경계선
        region[x+i][y+i] = 5;
        region[x+d1+i][y-d1+i] = 5;
    }

    // 2. 5구역 채우고 5구역 인구 세기
    for(int r = x; r <= x+d1+d2; r++) {
        int start = n, end = 1;
        for(int c = y-d1; c <= y+d2; c++) {
            if(region[r][c] == 5) {
                start = min(start, c);
                end = max(end, c);
            }
        }
        for(int c = start; c <= end; c++) { // 경계선 내부 채우고 인구 카운트
            region[r][c] = 5;
            cnt += a[r][c];
        }
    }
    return cnt;
}

int bruteforce() {
    int answer = INF;
    for(int d1 = 1; d1 <= n; d1++) {
        for(int d2 = 1; d2 <= n; d2++) {
            for(int x = 1; x <= n-d1-d2; x++) {
                for(int y = d1+1; y <= n-d2; y++) {
                    vector<vector<int>> region(n+1, vector<int> (n+1, 0));
                    int tmp = cntPop5(x, y, d1, d2, region);
                    int max_pop = tmp, min_pop = tmp;

                    vector<vector<int>> range = { // 구역별 범위
                            {1, x+d1, 1, y+1, 1},
                            {1, x+d2+1, y+1, n+1, 2},
                            {x+d1, n+1, 1, y-d1+d2, 3},
                            {x+d2+1, n+1, y-d1+d2, n+1, 4}
                    };
                    for(int i = 0; i < 4; i++) {
                        tmp = cntPop(range[i][0], range[i][1], range[i][2], range[i][3], range[i][4], region);
                        max_pop = max(max_pop, tmp);
                        min_pop = min(min_pop, tmp);
                    }
                    answer = min(answer, max_pop-min_pop);
                }
            }
        }
    }
    return answer;
}

int main() {
    cin >> n;
    a.assign(n+1, vector<int> (n+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << bruteforce();
    return 0;
}