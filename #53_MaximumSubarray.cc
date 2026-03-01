class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        for (int num : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += num;
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};