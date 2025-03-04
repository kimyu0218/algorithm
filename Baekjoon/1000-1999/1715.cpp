#include <iostream>
#include <queue>

using namespace std;

int minComp(int n, priority_queue<int, vector<int>, greater<>> &bundle) { // 카드 최소 비교 횟수 세기
    int comp = 0; // 카드 비교 횟수
    while(bundle.size() >= 2) { // 카드 합치기
        int b1 = bundle.top(); bundle.pop();
        int b2 = bundle.top(); bundle.pop();
        int sum = b1 + b2;
        comp += sum;
        bundle.push(sum);
    }
    return comp;
}

int main() {
    int n, size;
    priority_queue<int, vector<int>, greater<>> bundle;

    cin >> n;
    for(int i = 0; i < n; i++) { // 카드 묶음 크기 입력
        cin >> size;
        bundle.push(size);
    }
    cout << minComp(n, bundle);
    return 0;
}