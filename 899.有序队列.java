import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=899 lang=java
 *
 * [899] 有序队列
 */

// @lc code=start
class Solution {
    public String orderlyQueue(String s, int k) {
        if (k == 1) {
            String res = s;
            StringBuilder sb = new StringBuilder(s);
            int n = s.length();
            for (int i = 1; i < n; ++i) {
                char c = sb.charAt(0);
                sb.deleteCharAt(0);
                sb.append(c);
                if (sb.toString().compareTo(res) < 0) {
                    res = sb.toString();
                }
            }
            return res;
        }
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }
}
// @lc code=end
