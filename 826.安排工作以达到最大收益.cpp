/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        int n = difficulty.size();
        // difPro 用来记录 排序 后的 difficulty 及其对应的 小于等于 该难度时能够获取的最大利润
        vector<pair<int, int>> difPro;
        difPro.reserve(n);
        for (int i = 0; i < n; ++i) {
            // 先记录每个 difficulty 对应的 profit 的下标
            difPro.emplace_back(difficulty[i], i);
        }
        sort(difPro.begin(), difPro.end());
        difPro[0].second = profit[difPro[0].second];
        for (int i = 1; i < n; ++i) {
            // 每个 difficulty 对应的利润为 小于等于 该难度时，能够获取的最大利润
            difPro[i].second = max(difPro[i - 1].second, profit[difPro[i].second]);
        }
        int res = 0;
        int m = worker.size();
        // 对每个工人进行二分查找，找到其能完成的最大难度，并根据 difPro 获得该难度下能够获取的最大利润
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if (difPro[mid].first <= worker[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            // l = 0 时表示该工人不能完成任何工作
            if (l != 0) res += difPro[l - 1].second;
        }
        return res;
    }
};
// @lc code=end
