#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, power;
    string nickname;
    cin >> n >> m;

    map<int, string> nick;
    for(int i = 0; i < n; i++) {
        cin >> nickname >> power;
        // 해당 전투력에 대한 칭호가 없는 경우만 저장
        if(nick[power] == "") nick[power] = nickname;
    }

    for(int i = 0; i < m; i++) {
        cin >> power;
        // power보다 작은 가장 큰 전투력의 칭호 출력
        cout << nick.lower_bound(power)->second << '\n';
    }
    return 0;
}