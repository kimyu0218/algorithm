class Solution {
public:
    int binarySearch1(int left, int right, int target, vector<int> &nums) {
        int answer = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(target <= nums[mid]) {
                if(target == nums[mid]) {
                    answer = mid;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return answer;
    }

    int binarySearch2(int left, int right, int target, vector<int> &nums) {
        int answer = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(target >= nums[mid]) {
                if(target == nums[mid]) {
                    answer = mid;
                }
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return answer;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        return {binarySearch1(left, right, target, nums), binarySearch2(left, right, target, nums)};
    }
};