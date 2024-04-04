#include <string>
#include <vector>

using namespace std;

int cnt_step(int friends, int n, vector<int> stones) {
    int step = 1;
    int pre = -1;

    for(int i = 0; i < n; i++) {
        if(stones[i] >= friends) {
            step = max(step, i - pre);
            pre = i;
        }
    }
    return max(step, n - pre);
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int n = stones.size();

    int left = 1;
    int right = 0;
    for(int i = 0; i < n; i++) {
        right = max(right, stones[i]);
    }

    while(left <= right) {
        int mid = (left + right) / 2;
        int step = cnt_step(mid, n, stones);

        if(step <= k) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}