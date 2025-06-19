#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    queue<int> q;

    while(n) {
        q.push(n % 3);
        n /= 3;
    }

    while(!q.empty()) {
        int exp = q.size() - 1;
        int coef = q.front();

        answer += (pow(3, exp) * coef);
        q.pop();
    }
    return answer;
}