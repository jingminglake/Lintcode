class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int size = nums.size();
        int m[size] = {0};
        m[0] = nums[0];
        int ans = m[0];
        for (int i = 1; i < size; i++) {
          m[i] = min(nums[i], nums[i] + m[i-1]);
          ans = min(ans, m[i]);
        }
        return ans;
    }
};
