#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int SIZE = 10;

vector<ll> nums;

void backtracking(char start, string num) {
    if(num.length() == SIZE) {
        return;
    }
    for(char i = start; i >= '0'; i--) {
        string new_num = num + i;
        nums.push_back(stoll(new_num));
        backtracking(i - 1, new_num);
    }
}

ll solution(int n) {
    backtracking('9', "");

    if(n > nums.size()) {
        return -1;
    }
    sort(nums.begin(), nums.end());
    return nums[n - 1];
}

int main() {
    int n;

    cin >> n;

    cout << solution(n);
    return 0;
}