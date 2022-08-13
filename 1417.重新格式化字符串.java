/*
 * @lc app=leetcode.cn id=1417 lang=java
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution {
    public String reformat(String s) {
        StringBuilder nums = new StringBuilder(), letters = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                nums.append(c);
            } else {
                letters.append((c));
            }
        }
        int a = nums.length(), b = letters.length();
        if (Math.abs(a - b) > 1) {
            return "";
        }
        StringBuilder ans = new StringBuilder();
        int p = 0, q = 0;
        if (b > a) {
            ans.append(letters.charAt(q++));
        }
        while (p < a && q < b) {
            ans.append(nums.charAt(p++));
            ans.append(letters.charAt(q++));
        }
        if (p < a) {
            ans.append(nums.charAt(p));
        }
        return ans.toString();
    }
}
// @lc code=end
