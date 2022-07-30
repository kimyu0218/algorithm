#include <iostream>
#include <queue>

using namespace std;

long long cost(int k, priority_queue<long long, vector<long long>, greater<>> chap) { // 최소 비용 구하기
    long long sum = 0; // 최소 비용 저장하는 변수
    while(!chap.empty()) {
        if(chap.size() == 1) break;
        long long tmp1 = chap.top(); chap.pop();
        long long tmp2 = chap.top(); chap.pop();
        sum += (tmp1 + tmp2); // (tmp1 + tmp2 == 임시 파일)
        chap.push(tmp1 + tmp2);
    }
    return sum;
}

int main() {
    int t, k, file;
    cin >> t; // 테스트 개수 입력

    while(t--) {
        cin >> k; // 소설 장수 입력

        priority_queue<long long, vector<long long>, greater<>> chapter; // (top이 가장 작은 수를 가리킴)
        for(int i = 0; i < k; i++) {
            cin >> file;
            chapter.push(file);
        }
        cout << cost(k, chapter) << '\n';
    }
    return 0;
}