#include <iostream>
#include <queue>

using namespace std;

long long cost(int k, priority_queue<long long, vector<long long>, greater<>> file) { // 최소 비용 구하기
    long long sum = 0; // 최소 비용 저장하는 변수
    while(!file.empty()) {
        if(file.size() == 1) break;
        long long tmp1 = file.top(); file.pop();
        long long tmp2 = file.top(); file.pop();
        sum += (tmp1 + tmp2); // (tmp1 + tmp2 == 임시 파일)
        file.push(tmp1 + tmp2);
    }
    return sum;
}

int main() {
    int t, k, f;
    cin >> t; // 테스트 개수 입력

    while(t--) {
        cin >> k; // 소설 장수 입력

        priority_queue<long long, vector<long long>, greater<>> file; // (top이 가장 작은 수를 가리킴)
        for(int i = 0; i < k; i++) {
            cin >> f;
            file.push(f);
        }
        cout << cost(k, file) << '\n';
    }
    return 0;
}