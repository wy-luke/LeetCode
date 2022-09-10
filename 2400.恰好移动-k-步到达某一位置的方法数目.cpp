/*
 * @lc app=leetcode.cn id=2400 lang=cpp
 *
 * [2400] 恰好移动 k 步到达某一位置的方法数目
 */

// @lc code=start

// 用哈希表
class Solution {
public:
    const int MOD = 1e9 + 7;
    const int OFFSET = 1000;
    int endPos;
    unordered_map<long long, long long> mp;
    int numberOfWays(int startPos, int _endPos, int k) {
        endPos = _endPos;
        return dfs(startPos, k);
    }

    long long dfs(int startPos, int k) {
        // 当无法到达 endPos 时返回 0
        if (abs(startPos - endPos) > k) {
            return 0;
        }
        // 此时若 k==0 即代表到达了 endPos
        // 若没有在 endPos，则一定 abs(startPos-endPos)>k，所以上面已经返回 0
        if (k == 0) {
            return 1;
        }

        // 加 OFFSET 是因为有负数，*1000 再 +k 就可以构造出一个唯一的数
        // 这就相当于把 startPos 和 k 左右拼在了一起，nb
        long long key = (startPos + OFFSET) * 1000 + k;
        if (!mp.count(key)) {
            mp[key] = (dfs(startPos + 1, k - 1) + dfs(startPos - 1, k - 1)) % MOD;
        }

        return mp[key];
    }
};

// 用数组
class Solution2 {
public:
    const int MOD = 1e9 + 7;
    int endPos;
    vector<vector<long long>> dp;
    int numberOfWays(int startPos, int _endPos, int k) {
        endPos = _endPos;
        // 要防止负数下标！！！所以构造 3000 长的数组
        dp.resize(3000, vector<long long>(1005, -1));
        return dfs(startPos, k);
    }

    long long dfs(int startPos, int k) {
        // 当无法到达 endPos 时返回 0
        if (abs(startPos - endPos) > k) {
            return 0;
        }
        // 此时若 k==0 即代表到达了 endPos
        // 若没有在 endPos，则一定 abs(startPos-endPos)>k，所以上面已经返回 0
        if (k == 0) {
            return 1;
        }

        if (dp[startPos + 1000][k] == -1) {
            dp[startPos + 1000][k] = (dfs(startPos + 1, k - 1) + dfs(startPos - 1, k - 1)) % MOD;
        }

        return dp[startPos + 1000][k];
    }
};
// @lc code=end
