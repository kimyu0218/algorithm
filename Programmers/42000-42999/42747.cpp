#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_h_index(int h, int n, vector<int> v) {
    int lb = lower_bound(v.begin(), v.end(), h) - v.begin();
    int ub = upper_bound(v.begin(), v.end(), h) - v.begin();

    return (n - lb >= h) && (ub <= h);
}

int parametric_search(vector<int> v) {
    int answer = 0;
    sort(v.begin(), v.end());

    int n = v.size();
    int left = 0;
    int right = v[n - 1];

    while(left <= right) {
        int mid = (left + right) / 2;
        bool result = is_h_index(mid, n, v);

        if(result) {
            left++;
            answer = max(answer, mid);
        }
        else {
            right--;
        }
    }
    return answer;
}

int solution(vector<int> citations) {
    return parametric_search(citations);
}