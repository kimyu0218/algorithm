#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> notebook;

vector<vector<int>> rotate90(vector<vector<int>> &sticker) { // 스티커 90도 회전하기
    int n = sticker.size(), m = sticker[0].size();
    vector<vector<int>> rotate (m, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            rotate[j][n-1-i] = sticker[i][j];
        }
    }
    return rotate;
}

bool possible(int sr, int sc, int sn, int sm, vector<vector<int>> &sticker) { // 스티커 붙일 수 있는가
    for(int i = 0; i < sn; i++) {
        for(int j = 0; j < sm; j++) {
            if(sticker[i][j] && notebook[i+sr][j+sc]) {
                return false;
            }
        }
    }
    return true;
}

void putStickerOn(int sr, int sc, int sn, int sm, vector<vector<int>> &sticker) { // 스티커 붙이기
    for(int i = 0; i < sn; i++) {
        for(int j = 0; j < sm; j++) {
            if(sticker[i][j]) {
                notebook[i+sr][j+sc] = 1;
            }
        }
    }
}

bool bruteforce(int idx, int k, int n, int m, vector<vector<vector<int>>> &stickers) {
    if(idx == k) { // 스티커 붙이기 끝
        return true;
    }

    // 1. 회전 없이 붙이기
    vector<vector<int>> tmp = stickers[idx];
    int sn = tmp.size(), sm = tmp[0].size();
    for(int i = 0; i <= n-sn; i++) {
        for(int j = 0; j <= m-sm; j++) {
            if(possible(i, j, sn, sm, tmp)) {
                putStickerOn(i, j, sn, sm, tmp);
                bool flag = bruteforce(idx+1, k, n, m, stickers);
                if(flag) {
                    return true;
                }
            }
        }
    }
    // 2. 회전하여 붙이기
    for(int s = 0; s < 3; s++) {
        tmp = rotate90(tmp);
        sn = tmp.size(); sm = tmp[0].size();
        for(int i = 0; i <= n-sn; i++) {
            for(int j = 0; j <= m-sm; j++) {
                if(possible(i, j, sn, sm, tmp)) {
                    putStickerOn(i, j, sn, sm, tmp);
                    bool flag = bruteforce(idx+1, k, n, m, stickers);
                    if(flag) {
                        return true;
                    }
                }
            }
        }
    }
    // 3. 회전시켜도 붙일 수 없는 경우 , 해당 스티커 pass
    return bruteforce(idx+1, k, n, m, stickers);
}

int cntCells(int n, int m, int k, vector<vector<vector<int>>> &stickers) {
    int cnt = 0;
    bruteforce(0, k, n, m, stickers);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(notebook[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m, k, r, c;
    vector<vector<vector<int>>> stickers;

    cin >> n >> m >> k;
    notebook.assign(n, vector<int> (m, 0));
    stickers.assign(k, vector<vector<int>>());

    for(int i = 0; i < k; i++) { // 스티커 정보 입력
        cin >> r >> c;
        vector<vector<int>> sticker (r, vector<int> (c, 0));
        for(int sr = 0; sr < r; sr++) {
            for(int sc = 0; sc < c; sc++) {
                cin >> sticker[sr][sc];
            }
        }
        stickers[i] = sticker;
    }

    cout << cntCells(n, m, k, stickers);
    return 0;
}