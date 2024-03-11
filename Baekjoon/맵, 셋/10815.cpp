#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, num;
    cin >> n;

    map<int, int> card;
    while(n--) { // 상근이가 가지고 있는 숫자 카드 입력
        cin >> num;
        card[num]++;
    }

    cin >> m;
    while(m--) { // 상근이가 갖고 있는 카드인가
        cin >> num;
        cout << ((card[num] > 0) ? 1 : 0) << ' ';
    }
    return 0;
}