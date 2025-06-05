#include <iostream>

using namespace std;

int solution(int n, int kim, int lim) {
    int answer = 1;
    int small = min(kim, lim);
    int big = max(kim, lim);

    while(n) {
        int t1 = (small + small % 2) / 2;
        int t2 = (big + big % 2) / 2;
        if(t1 == t2) {
            return answer;
        }
        small = t1;
        big = t2;
        n /= 2;
        answer++;
    }
    return -1;
}

int main() {
    int n, kim, lim;

    cin >> n >> kim >> lim;

    cout << solution(n, kim, lim);

    return 0;
}