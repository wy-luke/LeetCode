/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        // lambda 表达式作为 Campare，当返回 true 时，left 先进入，后输出，即在优先级队列（堆）的下方
        // 此处当 left.second < right.second 时返回 true，即较小的值先进入优先级队列，即大顶堆
        auto cmp = [](pair<int, int> left, pair<int, int> right) -> bool { return left.second < right.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums2.size(); ++i) {
            pq.emplace(i, nums2[i]);
        }
        // 默认为升序排列
        sort(nums1.begin(), nums1.end());

        int left = 0, right = nums1.size() - 1;
        vector<int> res(nums1.size());
        while (left <= right) {
            pair<int, int> pair = pq.top();
            pq.pop();
            if (nums1[right] > pair.second) {
                res[pair.first] = nums1[right];
                --right;
            } else {
                res[pair.first] = nums1[left];
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end
