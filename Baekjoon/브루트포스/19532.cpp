#include <iostream>

using namespace std;

const int MAX = 999;
const int MIN = -MAX;

typedef pair<int, int> pi;

bool check_equation(int p, int q, int r, int x, int y) {
    return r == p * x + q * y;
}

pi solution(int a, int b, int c, int d, int e, int f) {
    for(int x = MIN; x <= MAX; x++) {
        for(int y = MIN; y <= MAX; y++) {
            if(check_equation(a, b, c, x, y) && check_equation(d, e, f, x, y)) {
                return {x, y};
            }
        }
    }
    return {MIN - 1, MIN - 1};
}

int main() {
    int a, b, c, d, e, f;
    
    cin >> a >> b >> c >> d >> e >> f;
    
    pi result = solution(a, b, c, d, e, f);
    
    cout << result.first << ' ' << result.second;
    return 0;
}