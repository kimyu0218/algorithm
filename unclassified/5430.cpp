#include <iostream>
#include <deque>
#include <string>

using namespace std;

string make_arr(bool reverse, deque<int> &d) { // 배열 재구성
    string temp = "[";
    if(!d.empty()) {
        if (reverse) { // 역순으로 출력
            while (d.size() > 1) {
                temp += to_string(d.back());
                temp += ',';
                d.pop_back();
            }
        } else { // 원래대로 출력
            while (d.size() > 1) {
                temp += to_string(d.front());
                temp += ',';
                d.pop_front();
            }
        }
        temp += to_string(d.back()); // 마지막 숫자 (콤마 없이 출력)
    }
    temp += ']';
    return temp;
}

deque<int> make_deque(string &arr) { // 덱 만들기
    deque<int> d;
    string temp = "";
    for (char ch: arr) {
        if (ch == '[') continue;
        else if((ch == ']' || ch == ',') && temp != "") {
            d.push_back(stoi(temp)); temp = "";
            continue;
        }
        else if(ch >= '0' && ch <= '9') temp += ch;
    }
    return d;
}

void ac_compute(string &cmd, string &arr) {
    bool error = false, reverse = false; // 에러 여부, 역순 여부
    deque<int> d = make_deque(arr);   // 덱 만들기 (숫자만)

    for (char ch: cmd) { // 명령어 처리
        if (ch == 'R') {
            reverse = !reverse; // 순서 반대로
            continue;
        }
        if (d.empty()) { // 더이상 원소가 없는 경우 error
            error = true;
            break;
        }
        if (reverse) d.pop_back(); // 역순인 경우
        else d.pop_front();        // 역순 아닌 경우
    }
    if(error) cout << "error\n";
    else cout << make_arr(reverse, d) << '\n';
}

int main() {
    int t, n;
    string p, arr;

    cin >> t;
    while(t--) {
        cin >> p;
        cin >> n;
        cin >> arr;
        ac_compute(p, arr);
    }
    return 0;
}