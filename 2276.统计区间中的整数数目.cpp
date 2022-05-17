/*
 * @lc app=leetcode.cn id=2276 lang=cpp
 *
 * [2276] 统计区间中的整数数目
 */

// @lc code=start
class CountIntervals {
private:
    // 也可以用 set<pair<int,int>>，但显然 map 更简洁一些
    // 注意 key 为 right，value 为 left，为了方便后面查找
    map<int, int> mp;
    int cnt = 0;

public:
    CountIntervals() {
    }

    void add(int left, int right) {
        int l = left, r = right;
        // 找到第一个右端点大于等于 left 的区间，即第一个与要添加区间重合的
        // 注意 key 为 right，value 为 left，也是为了这里方便查找
        auto p = mp.lower_bound(left);
        // 往后遍历，直到某个区间左端点大于 right，即
        while (p != mp.end() && p->second <= right) {
            // 维护 [l, r] 为合并后的区间
            l = min(l, p->second);
            r = max(r, p->first);
            // 删除后面要合并的区间，并减少 cnt
            cnt -= p->first - p->second + 1;
            mp.erase(p++);
        }
        // 添加合并后的区间
        cnt += r - l + 1;
        mp[r] = l;
    }

    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end
