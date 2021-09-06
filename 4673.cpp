#include <iostream>
#include <vector>
#include<cmath>
#include <queue>

using namespace std;
vector<bool> self;

int digit(int num, int index) { // 자릿수 반환
    return (int) (num/pow(10, index));
}

void findNonSelf() { // nonSelf 숫자 찾기
    int d = 1;
    while(d <= 10000) {
        int tmp = d;

        queue<int> q; // 자릿수 저장하는 큐
        bool flag = false;
        for(int i = 4; i >= 0; i--) { // (10^4 -> 10^3 -> 10^2 -> 10^1 -> 10^0)
            if(digit(tmp, i)) {
                q.push(digit(tmp, i));
                flag = true;
            }
            else if(flag || i == 0) q.push(digit(tmp, i));
            tmp %= (int) pow(10, i);
        }

        int cmp = d;
        while(!q.empty()) {
            cmp += q.front();
            q.pop();
        }

        if(cmp <= 10000) self[cmp-1] = false;
        d++;
    }
}

int main() {
    self.assign(10000, true);
    findNonSelf();

    for(int i = 0; i < 10000; i++) {
        if(self[i]) cout << i+1 << '\n'; // self 숫자만 출력
    }
    return 0;
}