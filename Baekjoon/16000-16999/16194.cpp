#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> p) {
    int n = p.size();
    vector<int> answer = p;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            answer[j] = min(answer[j], p[i] + answer[j - 1 - i]);
        }
    }
    return answer[n - 1];
}

int main() {
    int n;
    vector<int> p;

    cin >> n;

    p.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solution(p);
    return 0;
}