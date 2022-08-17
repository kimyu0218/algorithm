#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct box { int from, to, cnt; }; // 보내는 마을, 받는 마을, 박스 개수

bool cmp(box &b1, box &b2) {
    if(b1.to != b2.to) return b1.to < b2.to; // 받는 마을 오름차순
    return b1.from < b2.from; // 받는 마을이 같다면 보내는 마을 오름차순
}

int deliver(int n, int c, int m, vector<box> b) {
    int max_box = 0;
    vector<int> truck(n, 0); // 마을별 트럭 용량
    for(int i = 0; i < m; i++) {
        // 1. 받는 마을까지 보낼 수 있는 박스 개수 계산하기
        int cnt = b[i].cnt;
        for(int j = b[i].from; j < b[i].to; j++)
            cnt = min(cnt, c-truck[j]);

        if(cnt <= 0) continue; // 박스 실을 수 없는 경우
        // 2. 박스 싣기
        for(int j = b[i].from; j < b[i].to; j++) truck[j] += cnt;
        max_box += cnt;
    }
    return max_box;
}

int main() {
    int n, c, m; // 마을 수, 트럭 용량, 박스 수
    cin >> n >> c >> m;

    vector<box> b(m, {0, 0, 0});
    for(int i = 0; i < m; i++) // 박스 정보 입력
        cin >> b[i].from >> b[i].to >> b[i].cnt;
    sort(b.begin(), b.end(), cmp); // 박스 정렬

    cout << deliver(n, c, m, b);
    return 0;
}