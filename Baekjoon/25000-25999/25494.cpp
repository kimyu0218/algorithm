#include <iostream>

using namespace std;

int solution(int a, int b, int c) {
    int result = 0;
    
    for(int x = 1; x <= a; x++) {
        for(int y = 1; y <= b; y++) {
            for(int z = 1; z <= c; z++) {
                int mod1 = x % y;
                int mod2 = y % z;
                int mod3 = z % x;
                
                result += (mod1 == mod2 && mod2 == mod3);
            }
        }
    }
    return result;
}

int main() {
    int t, a, b, c;
    
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        
        cout << solution(a, b, c) << '\n';
    }
    return 0;
}