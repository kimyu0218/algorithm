#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    sort(array.begin(), array.end());

    int answer = array[0];
    int left = 0;
    int right = array.size() - 1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(array[mid] == n) {
            return n;
        }

        int diff = abs(n - array[mid]);
        int cmp_diff = abs(n - answer);

        if(diff < cmp_diff) {
            answer = array[mid];
        }
        if(array[mid] < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}