#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decimalToNSystem(int n, int decimal) { // 10진법 -> N진법
    string n_system = "";
    if(decimal == 0) { // 0 바로 리턴
        return "0";
    }
    while(decimal > 0) {
        int q = decimal % n;
        if(q >= 10) { // 10 이상의 수는 알파벳 대문자로 변경
            n_system += ('A' + q-10);
        }
        else { // 9 이하의 수는 숫자 그대로 사용
            n_system += to_string(q);
        }
        decimal /= n;
    }
    reverse(n_system.begin(), n_system.end());
    return n_system;
}

vector<int> tubeIdx(int p, int m, int len) { // 튜브가 부를 숫자의 인덱스
    vector<int> tube_idx;
    int n = len/m;
    for(int i = 0; i < n; i++) {
        int idx = i*m+p-1;
        tube_idx.push_back(idx);
    }
    return tube_idx;
}

string solution(int n, int t, int m, int p) { // n진법, t개의 숫자, m명, p번째 튜브
    string tube = "", num_list = "";
    for(int i = 0; i <= t*100; i++) {
        num_list += decimalToNSystem(n, i); // i를 n진수로 전환
    }

    int len = num_list.length();
    vector<int> tube_idx = tubeIdx(p, m, len); // 튜브가 부를 숫자 위치
    for(int i = 0; i < t; i++) { // t개만큼 말하기
        tube += num_list[tube_idx[i]];
    }
    return tube; // 튜브가 말해야 하는 숫자들 반환
}