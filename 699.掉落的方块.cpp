/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        int h = 0;
        vector<int> res;
        // right left,height
        map<int, pair<int, int>> mp;
        for (vector<int> &position : positions) {
            // 该区间右端点
            int r = position[0] + position[1];
            auto p = mp.upper_bound(position[0]);
            // 相交区间的最大高度
            int tmp = 0;
            // 加入左侧不相交部分
            if (p != mp.end() && p->second.first < position[0]) {
                mp[position[0]] = make_pair(p->second.first, p->second.second);
                // 注意这里不能直接删除，防止同时左侧和右侧不相交
                // tmp = max(tmp, p->second.second);
                // mp.erase(p++);
            }
            while (p != mp.end() && p->second.first < r) {
                tmp = max(tmp, p->second.second);
                // 右侧不相交部分
                if (p->first > r) {
                    p->second = make_pair(r, p->second.second);
                } else {
                    mp.erase(p++);
                }
            }
            mp[r] = make_pair(position[0], tmp + position[1]);
            h = max(h, tmp + position[1]);
            res.emplace_back(h);
        }
        return res;
    }
};
// @lc code=end
