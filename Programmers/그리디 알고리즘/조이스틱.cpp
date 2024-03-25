#include <string>
#include <vector>

using namespace std;

const char A = 'A';
const int ALPHA = 26;
const int INF = 20 * (ALPHA + 1);

string make_initial_string(int len) {
    string result = "";
    for(int i = 0; i < len; i++) {
        result += A;
    }
    return result;
}

int cnt_up_down(int len, string s1, string s2) {
    int result = 0;
    for(int i = 0; i < len; i++) {
        if(s1[i] == s2[i]) {
            continue;
        }

        int up = (s2[i] - s1[i] + ALPHA) % ALPHA;
        int down = (s1[i] - s2[i] + ALPHA) % ALPHA;
        result += min(up, down);
    }
    return result;
}

vector<int> find_diff_pos(int len, string s1, string s2) {
    vector<int> result;
    for(int i = 0; i < len; i++) {
        if(s1[i] != s2[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int cnt_cursor(int len, string s1, string s2) {
    vector<int> diff_pos = find_diff_pos(len, s1, s2);

    int n = diff_pos.size();
    int only_l = len - diff_pos[0];
    int only_r = diff_pos[n - 1];
    int lr = INF;

    for(int i = 0; i < n - 1; i++) {
        int r = diff_pos[i];
        int l = len - diff_pos[i + 1];

        lr = min(lr, min(l, r) * 2 + max(l, r));
    }
    return min(lr, min(only_l, only_r));
}

int solution(string name) {
    int len = name.length();
    string curr = make_initial_string(len);

    if(curr == name) {
        return 0;
    }
    return cnt_up_down(len, curr, name) + cnt_cursor(len, curr, name);
}