#include <string>
#include <vector>
#include <queue>

using namespace std;

int compress(string s, int size, int s_len) { // 문자열 압축
    string compressed = ""; // 압축된 문자열
    queue<string> q; // 부분 문자열 저장

    int pos; // pos : 부분 문자열 시작 위치
    for(pos = 0; pos < s_len; pos += size) {
        q.push(s.substr(pos, size));
    }

    while(!q.empty()) {
        string unit = q.front(); // 압축 단위
        q.pop();
        int cnt = 1; // 압축 카운트 수

        while(!q.empty()) { // 압축 시작
            string cmp = q.front();
            if(unit != cmp) { // 압축 단위와 부분 문자열이 같지 않은 경우 break
                break;
            }
            cnt++; // 압축 카운트 증가
            q.pop();
        }

        if(cnt > 1) { // 압축 성공
            compressed += to_string(cnt);
        }
        compressed += unit;
    }
    return compressed.length(); // 압축된 문자열 길이 반환
}

int bruteforce(string s) { // 압축 크기 브루트포스
    int s_len = s.length();
    int slice_size = s_len/2, min_len = s_len;
    for(int i = 1; i <= slice_size; i++) {
        min_len = min(min_len, compress(s, i, s_len));
    }
    return min_len; // 압축된 문자열의 최소 길이
}

int solution(string s) {
    return bruteforce(s);
}