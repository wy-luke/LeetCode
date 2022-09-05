/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size(), ans = 1;
        vector<int> cnts(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; --j) {
                if (pairs[j][1] < pairs[i][0]) {
                    cnts[i] = 1 + cnts[j];
                    break;
                }
            }
            ans = max(ans, cnts[i]);
        }
        return ans;
    }
};

// 相似解法 300. 最长递增子序列
class Solution2 {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        // arr[i] 为长度是 i+1 的对数链的最小结尾 y
        // 记录最小是因为这样可以有更大机会构造更长对数链
        vector<int> arr;
        for (auto &pair : pairs) {
            int x = pair[0], y = pair[1];
            if (arr.size() == 0 || x > arr.back()) {
                arr.emplace_back(y);
            } else {
                // 找到当前数对可以插入的位置
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                arr[idx] = min(arr[idx], y);
            }
        }
        return arr.size();
    }
    return arr.size();
};
// @lc code=end
