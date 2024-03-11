#include <iostream>
#include <vector>

using namespace std;

int cntRain(int w, vector<int> &block) {
    int rain = 0;
    for(int i = 1; i < w-1; i++) { // i번째 블록
        int left = block[i], right = block[i];
        for(int j = i-1; j >= 0; j--) { // 가장 높은 왼쪽 블록 높이 찾기
            if(block[j] > left) {
                left = block[j];
            }
        }
        for(int j = i+1; j < w; j++) { // 가장 높은 오른쪽 블록 높이 찾기
            if(block[j] > right) {
                right = block[j];
            }
        }
        rain += (min(left, right) - block[i]); // 쌓이는 빗물의 양 더하기
    }
    return rain;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int h, w;
    vector<int> block;

    cin >> h >> w;
    block.assign(w, 0);
    for(int i = 0; i < w; i++) {
        cin >> block[i];
    }

    cout << cntRain(w, block);
    return 0;
}