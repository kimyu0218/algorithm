#include <string>
#include <vector>

using namespace std;

// 한 번에 건너뛸 수 있는 디딤돌의 최대 칸 수가 k일 때, 최대 몇 명까지 징검다리를 건널 수 있는가?
// == n명이 건너기 위해서 한 번에 건너뛸 수 있는 디딤돌의 최대 칸 수는?
int cnt_step(int n, vector<int> stones) { // n명이 건너기 위해 한 번에 건너뛸 수 있는 최대 칸 수 구하기
    int step = 1, prev = -1;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] >= n)  { // 발을 디딜 수 있는 경우
            step = max(i-prev, step);
            prev = i;
        }
    }
    step = max((int) stones.size()-prev, step); // 오른쪽까지 완전히 건너는 경우
    return step;
}

int max_people(int left, int right, int k, vector<int> stones) {
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int step = cnt_step(mid, stones);

        if(step <= k) { // 1. 최대 칸 수 k를 위배하지 않고 건넌 경우 -> 인원 늘리기
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1; // 2. 최대 칸 수 k를 위배한 경우 -> 인원 줄이기
    }
    return ans;
}
int solution(vector<int> stones, int k) {
    int right = 0;
    for(int i = 0; i < stones.size(); i++)
        right = max(right, stones[i]);
    // stones의 각 원소들의 값이 1이상이므로 최솟값은 1
    return max_people(1, right, k, stones);
}