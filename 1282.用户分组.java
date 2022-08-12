import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=1282 lang=java
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < groupSizes.length; ++i) {
            int num = groupSizes[i];
            mp.putIfAbsent(num, new ArrayList<Integer>());
            mp.get(num).add(i);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int k : mp.keySet()) {
            List<Integer> v = mp.get(k);
            int sz = v.size();
            for (int i = 0; i < sz; i += k) {
                List<Integer> group = new ArrayList<>();
                for (int j = 0; j < k; ++j) {
                    group.add(v.get(i + j));
                }
                ans.add(group);
            }
        }
        return ans;
    }
}
// @lc code=end
