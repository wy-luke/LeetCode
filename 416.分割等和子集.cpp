/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 != 0) return false;
        // 求到 sum / 2 即可满足题目要求
        sum = sum / 2;
        int n = nums.size();
        // 原二维 dp[i][j] 代表对前 i 个物品，容量为 j 时能否恰好装满
        // 因为状态转移时 dp[i][...] 只和 dp[i-1][..] 有关，所以可以将状态压缩为一维
        // dp[j] 代表容量为 j 时能否恰好装满（对前 i 个物品，被压缩）
        vector<bool> dp(sum + 1);
        // base case 当容量为 0 时，无论如何都能恰好装满
        dp[0] = true;
        // 从第 1 个物品遍历到第 n 个，容量从 1 遍历到 sum
        for (int i = 1; i <= n; ++i) {
            // dp[i][j] 和 dp[i-1][j-...] 有关，即后面的项依赖于前面的，所以需要从后往前遍历
            // 否则前面的项先更新，导致后面的项计算时出错
            for (int j = sum; j >= 1; --j) {
                // 第 i 个物品对应的是 nums[i-1]
                if (j - nums[i - 1] >= 0) {
                    dp[j] = dp[j - nums[i - 1]] || dp[j];
                }
            }
        }
        return dp[sum];
    }
};
// @lc code=end
