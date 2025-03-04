#include <iostream>

using namespace std;

const int CNT = 10;
const int NOW = 1e2;
const int MAX = 5 * 1e5;

bool breakdown[CNT] = { false, };

bool can_move_directly(string channel) {
    for(int i = 0; i < channel.length(); i++) {
        int digit = channel[i] - '0';
        if(breakdown[digit]) {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int result = abs(n - NOW);

    for(int i = 0; i <= 2 * MAX; i++) {
        string channel = to_string(i);

        if(can_move_directly(channel)) {
            int direct = channel.length();
            int up_down = abs(n - i);
            result = min(result, direct + up_down);
        }
    }
    return result;
}

int main() {
    int n, m, num;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> num;
        breakdown[num] = true;
    }

    cout << solution(n);
    return 0;
}