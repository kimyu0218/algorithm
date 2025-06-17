#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

vector<int> solution(int n, int m) {
    int g = gcd(max(n, m), min(n, m));

    return { g, n * m / g };
}