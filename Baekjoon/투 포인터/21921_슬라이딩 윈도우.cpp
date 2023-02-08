#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

pi slidingWindow(int n, int x, vector<int> &hit) {
    int max = 0, cnt = 0, part_sum = 0;
    int left = 0, right = x;

    for(int i = left; i < right; i++) {
        part_sum += hit[i];
    }
    if(part_sum > max) {
        max = part_sum;
        cnt = 1;
    }

    while(left < n-x) {
        part_sum -= hit[left++];
        part_sum += hit[right++];

        if(part_sum > max) {
            max = part_sum;
            cnt = 1;
        }
        else if(part_sum == max) {
            cnt++;
        }
    }
    return {max, cnt};
}

int main() {
    int n, x;
    vector<int> hit;

    cin >> n >> x;
    hit.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> hit[i];
    }

    pi ans = slidingWindow(n, x, hit);
    if(ans.first == 0) {
        cout << "SAD";
    }
    else {
        cout << ans.first << '\n' << ans.second;
    }
    return 0;
}