#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
const int SIZE = 100000;
vector<int> prime;
map<int, int> result; // 밑과 지수 저장하는 맵

void isPrime() { // 소수 설정하기
    prime.assign(SIZE+1, 0);
    for(int i = 2; i <= SIZE; i++) prime[i] = i;

    for(int i = 2; i <= sqrt(SIZE); i++) {
        if(prime[i] != i) continue;
        for(int j = i*i; j <= SIZE; j+=i)
            if(prime[j] == j) prime[j] = i;
    }
}

// (정수 여부를 판단하므로 부호 무시)
void multi_fact(int num) { // 곱하기
    num = abs(num);
    while(num > 1) {
        result[prime[num]]++;
        num /= prime[num];
    }
}

void divide_fact(int num) { // 나누기
    num = abs(num);
    while(num > 1) {
        result[prime[num]]--;
        num /= prime[num];
    }
}

string isMintChoco() { // 민트 초코 여부 판별하기
    for(auto iter = result.begin(); iter != result.end(); iter++)
        if(iter->second < 0) return "toothpaste"; // 유리수인 경우
    return "mint chocolate"; // 정수인 경우
}

int main() {
    int n, num;
    bool is_zero = false; // 0을 입력하는 경우 무조건 정수
    char op;
    cin >> n;

    isPrime(); // 소수 설정하기

    // 첫번째 숫자 입력하기 (분자)
    cin >> num;
    multi_fact(num);
    if(num == 0) is_zero = true;
    cin.ignore();
    n--;

    while(n--) { // 나머지 숫자 입력하기
        cin >> op >> num;
        if(num == 0) is_zero = true;
        if(!is_zero) {
            switch(op) {
                case '*': // 곱셈 (분자)
                    multi_fact(num);
                    break;
                case '/': // 나눗셈 (분모)
                    divide_fact(num);
                    break;
            }
        }
        cin.ignore();
    }

    if(is_zero) cout << "mint chocolate";
    else cout << isMintChoco(); // 민트 초코 여부 출력
    return 0;
}