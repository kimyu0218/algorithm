#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 5;

int main() {
    int sum = 0;
    vector<int> num(SIZE, 0);

    for(int i = 0; i < SIZE; i++) { // 숫자 입력
        cin >> num[i];
        sum += num[i];
    }
    sort(num.begin(), num.end());

    cout << sum/SIZE << '\n';
    cout << num[2];
    return 0;
}