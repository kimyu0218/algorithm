#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

string solution(string number, int k) { // (k : 제거해야 하는 수의 개수)
    string answer = "";

    int cnt = 0, pre = -1, len = number.length(), num_len = len - k;
    vector<pair<char, int>> sorted; // (first : 숫자, second : 인덱스)
    for(int i = 0; i < len; i++) sorted.push_back({number[i], i});
    sort(sorted.begin(), sorted.end(), cmp);

    for(int i = 0; i < len; i++) {
        int idx = sorted[i].second;
        if(len-idx >= num_len-cnt && idx > pre) {
            answer += sorted[i].first;
            cnt++; pre = idx;
            for(int j = 0; j < idx; j++) {
                if(cnt == num_len) return answer;
                int idx2 = sorted[j].second;
                if(len-)
            }
        }
    }
    return answer;
}

int main() {
    // 예제 1
    /*string number = "1924";
    int k = 2;*/

    // 예제 2
    string number = "1231234";
    int k = 3;

    // 예제 3
    string number = "4177252841";
    int k = 4;

    cout << solution(number, k);
    return 0;
}