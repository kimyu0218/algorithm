#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int n = queue1.size();
    ll sum1 = 0, sum2 = 0;

    queue<int> q1, q2;
    for(int i = 0; i < n; i++) {
        sum1 += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i = 0; i < n; i++) {
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }

    // 모든 원소의 합이 홀수라면 두 큐의 합을 같게 만들 수 없음
    if((sum1 + sum2) % 2) {
        return -1;
    }

    int cnt = 0;
    while(cnt <= 3*n) {
        if(sum1 == sum2) {
            return cnt;
        }
        if(sum1 > sum2) {
            int pop = q1.front();
            q1.pop();
            q2.push(pop);
            sum1 -= pop;
            sum2 += pop;
        }
        else {
            int pop = q2.front();
            q2.pop();
            q1.push(pop);
            sum1 += pop;
            sum2 -= pop;
        }
        cnt++;
    }
    return -1;
}