/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */

// @lc code=start
class Solution {
public:
    vector<int> pre;
    vector<vector<int>> rect;
    Solution(vector<vector<int>> &rects) {
        rect = rects;

        int n = rects.size();
        pre.resize(n + 1);
        // 以正方形包含的所有点数为前缀和
        // 注意不能单纯是面积！面积不等价于包含点数，也没有比例关系，所以会错
        for (int i = 0; i < n; ++i) {
            // 方形包含的所有点数
            pre[i + 1] = pre[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
        }
    }

    vector<int> pick() {
        // [1,pre[n]]
        int r = 1 + rand() % pre.back();
        // 二分查找
        auto it = lower_bound(pre.begin(), pre.end(), r);
        // -1 为找到对应的方形下标
        int index = it - pre.begin() - 1;
        // 方形内取随机
        int x = rect[index][0] + rand() % (rect[index][2] - rect[index][0] + 1);
        int y = rect[index][1] + rand() % (rect[index][3] - rect[index][1] + 1);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
