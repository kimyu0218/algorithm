#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, num;
    cin >> n;

    map<int, int> card;
    for(int i = 0; i < n; i++) {
        cin >> num;
        card[num]++;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> num;
        cout << card[num] << ' ';
    }
    return 0;
}