#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int compute_year(int year, int max_year) {
    int mod = year % max_year;
    return mod == 0 ? max_year : mod;
}

int solution(int m, int n, int x, int y) {
    int l = lcm(max(m, n), min(m, n));
    
    for(int k = x; k <= l; k += m) {
        if(y == compute_year(k, n)) {
            return k;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, m, n, x, y;
    
    cin >> t;
    while(t--) {
        cin >> m >> n >> x >> y;
        
        cout << solution(m, n, x, y) << '\n';
    }
    return 0;
}