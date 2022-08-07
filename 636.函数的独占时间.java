import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

/*
 * @lc app=leetcode.cn id=636 lang=java
 *
 * [636] 函数的独占时间
 */

// @lc code=start
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        // 记录 id 和 start 时间
        Deque<int[]> stk = new ArrayDeque<>();
        int[] res = new int[n];
        for (String log : logs) {
            String[] ss = log.split(":");
            int curId = Integer.parseInt(ss[0]);
            int curTime = Integer.parseInt(ss[2]);

            if (ss[1].equals("start")) {
                // 如果存在上层函数，则先计算上层函数到此的用时
                if (!stk.isEmpty()) {
                    res[stk.peekLast()[0]] += curTime - stk.peekLast()[1];
                }
                stk.addLast(new int[] { curId, curTime });
            } else {
                res[curId] += curTime - stk.pollLast()[1] + 1;
                // 如果存在上层函数，到这里需要重新计时，更新开始时间为该层函数结束时间+1
                if (!stk.isEmpty()) {
                    stk.peekLast()[1] = curTime + 1;
                }
            }
        }
        return res;

    }
}
// @lc code=end
