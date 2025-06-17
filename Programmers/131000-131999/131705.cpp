#include <string>
#include <vector>

using namespace std;

const int CNT = 3;

int answer = 0;
int arr[CNT];

void backtracking(int idx, int start, int n, vector<int> &number) {
    if(idx == CNT) {
        int sum = 0;
        for(int i = 0; i < CNT; i++) {
            sum += arr[i];
        }
        answer += (sum == 0);
        return;
    }
    if(start >= n) {
        return;
    }

    arr[idx] = number[start];
    backtracking(idx + 1, start + 1, n, number);
    arr[idx] = 0;
    backtracking(idx, start + 1, n, number);
}

int solution(vector<int> number) {
    backtracking(0, 0, number.size(), number);
    return answer;
}