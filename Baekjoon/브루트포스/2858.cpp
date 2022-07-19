#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> divisor(int n) { // 2보다 크거나 같고 루트 n보다 작거나 같은 n의 약수 구하기
    vector<int> div;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) div.push_back(i); // i가 n의 약수인 경우 push
    }
    return div;
}

int main() {
    int r, b;
    cin >> r >> b;

    int total = r + b; // 총 타일 개수
    vector<int> div = divisor(total);

    for(int i = 0; i < div.size(); i++) {
        int l = total / div[i], w = div[i]; // (div안에는 루트 n보다 작거나 같은 약수만 들어있으므로 l >= w를 항상 만족한다)
        if(b == (l-2) * (w-2)) { // 갈색 타일의 개수을 만족하는 경우
            cout << l << ' ' << w;
            break;
        }
    }
    return 0;
}