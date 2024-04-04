#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    vector<int> cards;

    cin >> n;

    cards.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> m;

    while(m--) {
        cin >> x;

        auto lb = lower_bound(cards.begin(), cards.end(), x);
        auto ub = upper_bound(cards.begin(), cards.end(), x);
        cout << ub - lb << ' ';
    }
    return 0;
}