#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000000;

long long cost(int n, vector<int> load, vector<int> gas) {
    long long answer = 0;

    // load : n-1개, gas : n개
    int min = MAX;
    for(int i = 0; i < n-1; i++) {
        if(min > gas[i]) min = gas[i];
        answer += (long long) load[i] * min;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> load(n-1, 0);
    for(int i = 0; i < n-1; i++) // 도로 길이 입력
        cin >> load[i];

    vector<int> gas(n, 0);
    for(int i = 0; i < n; i++) //  주유소 리터당 가격 입력
        cin >> gas[i];

    cout << cost(n, load, gas);
    return 0;
}