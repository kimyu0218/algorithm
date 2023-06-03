class Solution {
public:
    typedef pair<int, int> pi;
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pi> sorted(n, {0, 0});
        for(int i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
        }
        sort(sorted.begin(), sorted.end());

        int left = 0, right = n-1;
        int answer = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(sorted[mid].first == target) {
                return sorted[mid].second;
            }
            if(sorted[mid].first < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return answer;
    }
};