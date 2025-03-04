#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int result = 0;
    
    int digit = to_string(n).length();
    for(int i = 1; i < digit; i++) {
        int cnt = pow(10, i) - pow(10, i - 1);
        result += i * cnt;
    }
    
    int cnt = (n + 1) - pow(10, digit - 1);
    return result + digit * cnt;
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}