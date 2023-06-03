class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int answer = right+1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] >= target) {
                right = mid - 1;
                answer = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return answer;
    }
};