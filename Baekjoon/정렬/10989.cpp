#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, tmp;
    cin >> n;

    map<int, int> m; // map 이용

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        m[tmp]++;
    }

    for(auto & iter : m) {
        for(int i = 0; i < iter.second; i++)
            cout << iter.first << '\n';
    }

    return 0;
}