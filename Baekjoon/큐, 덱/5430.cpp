#include <iostream>
#include <string>
#include <deque>

using namespace std;

void print(deque<string> &d) { // 출력
    while(d.size() != 1) {
        cout << d.front() << ",";
        d.pop_front();
    }
    cout << d.front(); // 마지막 숫자 출력
}

void printReverse(deque<string> &d) { // 역순으로 출력
    while(d.size() != 1) {
        cout << d.back() << ",";
        d.pop_back();
    }
    cout << d.back(); // 마지막 숫자 출력
}

void initializeDeque(deque<string> &d, string arr) { // 덱 초기화
    string num = ""; // 숫자 임의로 저장하는 변수
    for(int i = 1; i < arr.length()-1; i++) {
        if(arr[i] == ',') {
            d.push_back(num);
            num = "";
        }
        else num += arr[i];
        if(i == arr.length() - 2) d.push_back(num); // 마지막 숫자 push
    }
}

int main() {
    int t, n;
    cin >> t;

    string p, arr;
    while(t--) {
        cin >> p >> n >> arr;

        bool reverse = false, error = false;
        deque<string> d;
        initializeDeque(d, arr); // 덱 초기화

        for(char i : p) { // 함수 실행
            // 1. 뒤집기
            if(i == 'R') reverse = !reverse;
            // 2. 버리기
            else if(i == 'D') {
                if(d.empty()) { error = true; break; } // error 발생하는 경우
                if(reverse) d.pop_back();
                else d.pop_front();
            }
        }
        if(error) cout << "error\n";
        else {
            cout << "[";
            if(reverse && !d.empty()) printReverse(d); // 역순으로 출력
            else if(!reverse && !d.empty()) print(d); // 출력
            cout << "]\n";
        }
    }
    return 0;
}