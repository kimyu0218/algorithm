#include <string>
#include <vector>

using namespace std;

const int MOD = 10;

int get_sum(int x) {
    int sum = 0;

    while(x) {
        sum += (x % MOD);
        x /= MOD;
    }
    return sum;
}

bool solution(int x) {
    int sum = get_sum(x);

    return (x % sum) ? false : true;
}