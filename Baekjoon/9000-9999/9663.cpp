#include <iostream>

using namespace std;

const int MAX = 15;

int result = 0;
bool visited1[MAX];
bool visited2[2 * MAX];
bool visited3[2 * MAX];

void solution(int row, int n) {
    if(row == n) {
        result++;
        return;
    }

    for(int col = 0; col < n; col++) {
        int sum = row + col;
        int diff = row - col + n;

        if(visited1[col] || visited2[sum] || visited3[diff]) {
            continue;
        }
        visited1[col] = visited2[sum] = visited3[diff] = true;
        solution(row + 1, n);
        visited1[col] = visited2[sum] = visited3[diff] = false;
    }
}

int main() {
    int n;

    cin >> n;

    solution(0, n);

    cout << result;
    return 0;
}