#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ws) {
    sort(ws.begin(), ws.end());

    int n = ws.size();
    int answer = ws[0] + ws[n - 1];

    for(int i = 1; i < n / 2; i++) {
        int wg = ws[i] + ws[n - 1 - i];
        answer = min(answer, wg);
    }
    return answer;
}

int main() {
    int n;
    vector<int> ws;

    cin >> n;

    ws.assign(2 * n, 0);
    for(int i = 0; i < 2 * n; i++) {
        cin >> ws[i];
    }

    cout << solution(ws);
    return 0;
}