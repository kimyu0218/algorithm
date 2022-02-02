#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<int> cor;
set<int> s;

int main() {
    int n;
    cin >> n;

    cor.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cor[i];
        s.insert(cor[i]);
    }

    for(int i = 0; i < n; i++) {
        int j = 0;
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            if(*iter == cor[i]) break;
            j++;
        }
        cout << j << ' ';
    }
    return 0;
}