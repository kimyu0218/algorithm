#include <iostream>
#include <vector>

using namespace std;

int cntGroup(int k, int n, vector<int> &bead) { // 그룹합의 최댓값이 k일 때, 몇개의 그룹을 구성할 수 있는가
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + bead[i] > k) { // 그룹 분리 시점
            cnt++;
            sum = 0;
        }
        sum += bead[i];
    }
    return cnt+1;
}

vector<int> makeGroup(int k, int n, int m, vector<int> &bead) { // 그룹합이 k를 초과하지 않는, m개의 그룹 만들기
    vector<int> group;

    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(sum + bead[i] > k) { // 그룹 분리 시점
            group.push_back(cnt);
            cnt = sum = 0;
            m--; // 그룹 만들기
        }
        sum += bead[i];
        cnt++;

        if(n-i == m) { // 나머지 그룹은 한명씩 분배
            group.push_back(cnt);
            while(--m) {
                group.push_back(1);
            }
            break;
        }
    }
    return group;
}

int binarySearch(int left, int right, int n, int m, vector<int> &bead) {
    int answer = right;
    while(left <= right) {
        int mid = (left + right) / 2; // 그룹합 최댓값
        int cnt = cntGroup(mid, n, bead);

        if(cnt <= m) { // 1. m개의 그룹을 만든 경우
            answer = mid;
            right = mid - 1;
        }
        else { // 2. m개의 그룹을 만들 수 없는 경우
           left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, sum = 0, max_num = 0;
    vector<int> bead;

    cin >> n >> m;
    bead.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> bead[i];
        max_num = max(max_num, bead[i]);
        sum += bead[i];
    }

    int ans1 = binarySearch(max_num, sum, n, m, bead);
    cout << ans1 << '\n';
    vector<int> ans2 = makeGroup(ans1, n, m, bead);
    for(int i = 0; i < m; i++) {
        cout << ans2[i] << ' ';
    }
    return 0;
}