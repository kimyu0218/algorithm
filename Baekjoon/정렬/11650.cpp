#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main () {
    int n, x, y;
    cin >> n;

    vector<pair<int, int>> cor;
    cor.assign(n, {0, 0});

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cor[i] = {x, y};
    }

    sort(cor.begin(), cor.end(), compare); // 오름차순 정렬

    for(int i = 0; i < n; i++)
        cout << cor[i].first << ' ' << cor[i].second << '\n';

    return 0;
}