#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(int n) {
    ll result = 0;
    
    for(int i = 1; i <= n; i++) {
        result += (n / i) * i;
    }
    return result;
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}