#include <iostream>
#include <string>

using namespace std;

bool is_end_num(long long n) { // 종말의 수 여부 판별
    if(to_string(n).find("666") == string::npos) return false;
    else return true;
}

long long series(int n) { // n번째 영화 제목 출력
    long long title = 666;
    int cnt = 0; // 시리즈 번호 카운트 하는 변수
    while(true) {
        cnt += is_end_num(title);
        if(cnt == n) break;
        title++;
    }
    return title;
}

int main() {
    int n;
    cin >> n;

    cout << series(n);
    return 0;
}