#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

vector<pi> sort_in_asc(int n, vector<int> a) {
    vector<pi> sorted (n, {0, 0});

    for(int i = 0; i < n; i++) {
        sorted[i] = { a[i], i };
    }

    sort(sorted.begin(), sorted.end());
    return sorted;
}

vector<int> get_p(int n, vector<int> a, vector<pi> sorted) {
    vector<int> p (n, 0);

    for(int i = 0; i < n; i++) {
        int original_idx = sorted[i].second;
        p[original_idx] = i;
    }
    return p;
}

vector<int> solution(vector<int> a) {
    int n = a.size();
    vector<pi> sorted = sort_in_asc(n, a);
    return get_p(n, a, sorted);
}

int main() {
    int n;
    vector<int> a;

    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> answer = solution(a);

    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}