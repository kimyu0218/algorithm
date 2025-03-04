#include <iostream>

using namespace std;
const int SIZE = 40000;

int answer[SIZE];

int binarySearch(int right, int k) {
    int left = 0;
    while(left < right) {
        int mid = (left + right) / 2;
        if(answer[mid] >= k) { // mid 위치의 수가 k보다 큰 경우
            right = mid;
        }
        else { // mid 위치의 수가 k보다 큰 경우
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, num, idx = 0;

    cin >> n;

    // 첫번째 포트 번호는 바로 넣기
    cin >> num;
    answer[idx] = num;

    for(int i = 1; i < n; i++) {
        cin >> num;
        if(answer[idx] < num) { // 더 큰 수가 들어온 경우, anwer에 num 추가
            answer[++idx] = num;
        }
        else { // 더 작은 수가 들어온 경우, lower bound 찾기
            int pos = binarySearch(idx+1, num);
            answer[pos] = num;
        }
    }

    cout << idx+1;
    return 0;
}