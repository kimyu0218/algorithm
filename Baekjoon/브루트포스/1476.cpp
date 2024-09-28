#include <iostream>

using namespace std;

const int E = 15;
const int S = 28;
const int M = 19;

int compute_year(int num, int max) {
    int mod = num % max;
    return mod == 0 ? max : mod;
}

int solution(int e, int s, int m) {
    int result = 1;
    while(true) {
        if(compute_year(result, E) == e 
        && compute_year(result, S) == s
        && compute_year(result, M) == m) {
            return result;
        }
        result++;
    }
}

int main() {
    int e, s, m;
    
    cin >> e >> s >> m;

    cout << solution(e, s, m);
    return 0;
}