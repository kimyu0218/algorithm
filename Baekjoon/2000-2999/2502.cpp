#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int get_b_quot(int a, int a_coef, int b_coef, int k) {
    int b_multi = k - a * a_coef;
    if(b_multi % b_coef) {
        return 0;
    }
    return b_multi / b_coef;
}

pi solution(int d, int k) {
    vector<int> a (d, 0);
    vector<int> b (d, 0);
    
    a[0] = b[1] = 1;
    b[0] = a[1] = 0;
    
    for(int i = 2; i < d; i++) {
       a[i] = a[i - 1] + a[i - 2];
       b[i] = b[i - 1] + b[i - 2];
    }
    
    for(int i = 1; i <= k / 2; i++) {
        int b_quot = get_b_quot(i, a[d - 1], b[d - 1], k);
        if(b_quot) {
            return { i, b_quot };
        }
    }
    return { -1, -1 };
} 

int main() {
    int d, k;
    
    cin >> d >> k;
    
    pi result = solution(d, k);
    
    cout << result.first << '\n' << result.second;
    return 0;
}