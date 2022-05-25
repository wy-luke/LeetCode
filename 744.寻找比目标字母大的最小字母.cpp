/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int l = 0, r = letters.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (letters[mid] - target <= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l == letters.size()) {
            return letters[0];
        } else {
            return letters[l];
        }
    }
};
// @lc code=end
