#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> cnt(n + 1, 1);
    cnt[0] = 0;

    for(int i = 0; i < lost.size(); i++) {
        cnt[lost[i]]--;
    }
    for(int i = 0; i < reserve.size(); i++) {
        cnt[reserve[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i]) {
            answer++;
            continue;
        }

        if(cnt[i - 1] != 2 && cnt[i + 1] != 2) {
            continue;
        }
        cnt[i]++;
        answer++;
        if(cnt[i - 1] == 2) {
            cnt[i - 1]--;
        }
        else {
            cnt[i + 1]--;
        }
    }
    return answer;
}