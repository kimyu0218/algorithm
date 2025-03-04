#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(vector<int> stock) {
    ll answer = 0;
    int n = stock.size();

    int peak = stock[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        if(stock[i] >= peak) {
            peak = stock[i];
            continue;
        }
        answer += (peak - stock[i]);
    }
    return answer;
}

int main() {
    int t, n;
    vector<int> stock;

    cin >> t;

    while(t--) {
        cin >> n;

        stock.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> stock[i];
        }

        cout << solution(stock) << '\n';
    }
    return 0;
}