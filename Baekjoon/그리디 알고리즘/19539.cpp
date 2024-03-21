#include <iostream>
#include <vector>

using namespace std;

const string YES = "YES";
const string NO = "NO";

int get_sum(vector<int> h) {
    int result = 0;
    for(int i = 0; i < h.size(); i++) {
        result += h[i];
    }
    return result;
}

int cnt_min_one(vector<int> h) {
    int result = 0;
    for(int i = 0; i < h.size(); i++) {
        result += (h[i] % 2 != 0);
    }
    return result;
}

bool solution(vector<int> h) {
    int sum = get_sum(h);
    int min_one = cnt_min_one(h);

    if(sum % 3 || sum / 3 < min_one) {
        return false;
    }
    return true;
}

int main() {
    int n;
    vector<int> h;

    cin >> n;

    h.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    string result = solution(h) ? YES : NO;

    cout << result;
    return 0;
}