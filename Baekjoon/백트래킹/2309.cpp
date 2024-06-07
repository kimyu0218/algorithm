#include <iostream>
#include <algorithm>

using namespace std;

const int SEVEN = 7;
const int NINE = 9;

bool stop = false;
int height[NINE];
int arr[SEVEN];

void backtracking(int idx, int start) {
    if(idx == SEVEN) {
        int sum = 0;
        for(int i = 0; i < SEVEN; i++) {
            sum += arr[i];
        }
        stop = (sum == 100);
        return;
    }

    for(int i = start; i < NINE; i++) {
        if(stop) {
            return;
        }
        arr[idx] = height[i];
        backtracking(idx + 1, i + 1);
    }
}

void solution() {
    sort(height, height + NINE);

    backtracking(0, 0);
}

int main() {
    for(int i = 0; i < NINE; i++) {
        cin >> height[i];
    }

    solution();

    for(int i = 0; i < SEVEN; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}