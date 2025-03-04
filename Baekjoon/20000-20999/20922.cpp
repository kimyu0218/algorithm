#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200000;
int dohyun[MAX+1] = { 0, }; // 도현이가 갖고 있는 아이템 저장
vector<int> a;

int max_len(int n, int k) {
    int ans = 0, left = 0, right = 0;

    dohyun[a[left]]++;
    while(left <= right && right < n) {
        // (right : 최근 아이템 가리킴)
        if(dohyun[a[right]] <= k) { // k개 이하 아이템 가짐 -> 수열 길이 늘리기
            ans = max(ans, right - left + 1);

            if(++right == n) break;
            dohyun[a[right]]++;
        }
        else { // k개를 초과하는 아이템 가짐 -> 수열 길이 줄이기
            dohyun[a[left]]--;
            left++;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << max_len(n, k);
    return 0;
}