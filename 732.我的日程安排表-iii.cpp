/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start
class MyCalendarThree {
public:
    // right, (left,count)
    map<int, pair<int, int>> mp;
    int res = 1;
    MyCalendarThree() {
    }

    int book(int start, int end) {
        // 找到第一个和目标区间相交的，因为 左闭右开，所以要用 upper_bound
        auto it = mp.upper_bound(start);
        // 左侧未相交部分
        if (it != mp.end() && it->second.first < start) {
            mp[start] = make_pair(it->second.first, it->second.second);
            it->second.first = start;
        }
        int tmp = start;
        while (it != mp.end() && it->second.first < end) {
            // 中间未相交部分
            if (tmp < it->second.first) {
                mp[it->second.first] = make_pair(tmp, 1);
            }
            // 相交部分 count++
            if (it->first <= end) {
                it->second.second++;
                res = max(res, it->second.second);
                tmp = it->first;
            } else {
                // 处理右侧未相交部分
                mp[end] = make_pair(it->second.first, it->second.second + 1);
                res = max(res, it->second.second + 1);
                it->second.first = end;
                tmp = end;
            }
            it++;
        }
        if (tmp != end) mp[end] = make_pair(tmp, 1);
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end
