/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int> &nums) {
        preSum.reserve(nums.size() + 1);
        preSum[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }

private:
    vector<int> preSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
