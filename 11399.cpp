#include<iostream>
#include<vector>

using namespace std;
vector<int> atm;

void ascending(int n) { // 오름차순 버블 정렬
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(atm[j] > atm[j+1])
                swap(atm[j], atm[j+1]);
        }
    }
}

long long computeMin(int n) {
    long long sum = 0, tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp += atm[i]; // i번째 사람
        sum += tmp;
    }
    return sum; // 모든 사람
}

int main() {
    int n;
    cin >> n;
    atm.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> atm[i];
    ascending(n);
    cout << computeMin(n); // 최솟값 계산
    return 0;
}