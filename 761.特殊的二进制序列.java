import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/*
 * @lc app=leetcode.cn id=761 lang=java
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution {
    public String makeLargestSpecial(String s) {
        if (s.length() <= 2) {
            return s;
        }
        List<String> subs = new ArrayList<>();
        for (int i = 0, j = 0, k = 0; i < s.length(); ++i) {
            k += s.charAt(i) == '1' ? 1 : -1;
            if (k == 0) {
                subs.add("1" + makeLargestSpecial(s.substring(j + 1, i)) + "0");
                j = i + 1;
            }
        }
        Collections.sort(subs, (a, b) -> b.compareTo(a));
        StringBuilder ans = new StringBuilder();
        for (String sub : subs) {
            ans.append(sub);
        }
        return ans.toString();
    }
}
// @lc code=end
