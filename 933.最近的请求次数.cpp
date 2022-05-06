/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
private:
    int left, count;
    vector<int> v;

public:
    RecentCounter() {
        left = 0;
        count = 0;
        v.reserve(10005);
    }

    int ping(int t) {
        v.emplace_back(t);
        int lBound = t - 3000;
        while (v[left] < lBound) {
            ++left;
        }
        return v.size() - left;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
