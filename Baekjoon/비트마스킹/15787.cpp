#include <iostream>
#include <vector>
#include <map>

using namespace std;

int cntTrain(int n, vector<int> &train) { // 은하수를 건널 수 있는 기차 수 세기
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[train[i]]++;
    }
    return m.size();
}

int main() {
    int n, m, option, i, x;
    vector<int> train;

    cin >> n >> m;
    train.assign(n, 0);
    while(m--) {
        cin >> option;
        if(option <= 2) {
            cin >> i >> x;
            if(option == 1) { // 1 i x
                train[i-1] |= (1 << (x-1));
            }
            else { // 2 i x
                train[i-1] &= ~(1 << (x-1));
            }
        }
        else {
            cin >> i;
            if(option == 3) { // 3 i : i번째 기차의 승객 한 칸씩 뒤로
                train[i-1] <<= 1;
                train[i-1] &= ~(1 << 20); // (전 20번째 승객, 현 21번째 승객 내림 처리)
            }
            else { // 4 i : i번째 기차의 승객 한 칸씩 앞으로
                train[i-1] &= ~1; // (전 1번째 승객 내림 처리)
                train[i-1] >>= 1;
            }
        }
    }

    cout << cntTrain(n, train);
    return 0;
}