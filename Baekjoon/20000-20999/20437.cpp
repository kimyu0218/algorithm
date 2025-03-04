#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int SIZE = 26;

pi twoPointer(string w, int k) {
    int short_len = w.length(), long_len = -1;
    vector<vector<int>> idx(SIZE, vector<int> (0)); // 문자별 위치 저장

    for(int i = 0; i < w.length(); i++) { // i 문자 위치 세팅
        idx[w[i]-'a'].push_back(i);
    }

    for(int i = 0; i < SIZE; i++) { // (i: 문자)
        if(idx[i].size() < k) { // i 문자가 k개보다 적은 경우 다음 문자 탐색
            continue;
        }

        int left = 0, right = k-1; // 슬라이딩 윈도우
        while(right < idx[i].size()) {
            int tmp_len = idx[i][right] - idx[i][left] + 1; // 구간 길이
            short_len = min(short_len, tmp_len);
            long_len = max(long_len, tmp_len);

            // 오른쪽으로 한 칸 씩 이동
            left++;
            right++;
        }
    }
    return {short_len, long_len};
}

int main() {
    int t, k;
    string w;

    cin >> t;
    while(t--) { // 테스트 케이스
        cin >> w;
        cin >> k;

        pi ans = twoPointer(w, k);
        if(ans.second == -1) { // 만족하는 연속 문자열이 없는 경우
            cout << -1 << '\n';
        }
        else {
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
    return 0;
}