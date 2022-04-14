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
        // dp[i][j] 代表对前 i 个物品，容量为 j 时能否恰好装满
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        // base case 当容量为 0 时，无论如何都能恰好装满
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        // 从第1个物品遍历到第n个，容量从1遍历到sum
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                // 这个主要是防止下面 j - nums[i] 作为下标时越界
                // 注意，第 1 个物体对应的是 nums[0]
                if (j - nums[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};