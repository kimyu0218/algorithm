#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> part_a, part_b;

vector<int> part_sum(int n, vector<int> v) {
    vector<int> part;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += v[j];
            part.push_back(sum);
        }
    }
    return part;
}

ll cnt_pair(int t) {
    ll cnt = 0;
    int a_size = part_a.size(), b_size = part_b.size();

    int left = 0, right = b_size-1; // a는 부배열 합이 작은 것부터, b는 부배열 합이 큰 것부터 탐색
    while(left < a_size && right >= 0) {
        int sum = part_a[left] + part_b[right];

        if(sum == t) { // 1. 두 부배열 합이 t인 경우
            ll cnt_a = 1, cnt_b = 1;
            // part_a[left]와 같은 부배열 합이 더 있는가
            while(left + 1 < a_size && part_a[left+1] == part_a[left]) {
                left++;
                cnt_a++;
            }

            // part_b[right]와 같은 부배열 합이 더 있는가
            while(right - 1 >= 0 && part_b[right-1] == part_b[right]) {
                right--;
                cnt_b++;
            }
            left++; right--;
            cnt += cnt_a * cnt_b;
        }
        else if(sum < t) left++; // 2. 두 부배열 합이 t보다 작은 경우 -> 큰 부배열 이용
        else right--; // 3. 두 부배열 합이 t보다 큰 경우 -> 작은 부배열 이용
    }
    return cnt;
}

int main() {
    int t, n, m;
    cin >> t >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    vector<int> b(m, 0);
    for(int i = 0; i < m; i++)
        cin >> b[i];

    part_a = part_sum(n, a);
    part_b = part_sum(m, b);
    sort(part_a.begin(), part_a.end());
    sort(part_b.begin(), part_b.end());

    cout << cnt_pair(t);
    return 0;
}