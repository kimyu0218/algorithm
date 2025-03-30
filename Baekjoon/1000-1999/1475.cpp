#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> cnt (9, 0);
    string str_n = to_string(n);

    for(int i = 0; i < str_n.length(); i++) {
        int digit = (str_n[i] == '9') ? 6 : str_n[i] - '0';
        cnt[digit]++;
    }

    for(int i = 0; i < 9; i++) {
        int tmp = (i == 6) ? (cnt[i] / 2 + cnt[i] % 2) : cnt[i];
        answer = max(answer, tmp);
    }
    return answer;
}

int main() {
    int n;

    cin >> n;

    cout << solution(n);
    return 0;
}