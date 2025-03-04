#include <iostream>
#include <set>

using namespace std;
const int SIZE = 26;

int twoPointer(int n, string input) {
    int answer = 0, left = 0, right = n-1, len = input.length();
    int pos[SIZE]; // pos[i] : i번째 알파벳이 마지막으로 등장한 위치 저장
    set<char> s; // 번역기가 인식하는 문자 저장

    for(int i = left; i <= right; i++) {
        char ch = input[i];
        s.insert(ch);
        pos[ch-'a'] = i;
    }

    while(true) {
        answer = max(answer, right+1-left);
        if(++right == len) { // 문자열 끝에 도달한 경우, 종료
            break;
        }

        char c = input[right]; // 이번에 추가하는 문자열
        s.insert(c);
        pos[c-'a'] = right; // 마지막으로 등장한 위치 갱신

        if(s.size() > n) { // 번역기가 인식할 수 있는 문자 개수 초과
            char pop = c; // 제거해야 하는 알파벳
            for(auto iter = s.begin(); iter != s.end(); iter++) { // 제거할 알파벳 찾기
                if(pos[pop-'a'] > pos[*iter-'a']) {
                    pop = *iter;
                }
            }
            s.erase(pop);
            left = pos[pop-'a'] + 1; // left 갱신
        }
    }
    return answer;
}

int main() {
    int n;
    string input;

    cin >> n;
    cin >> input;
    cout << twoPointer(n, input);
    return 0;
}