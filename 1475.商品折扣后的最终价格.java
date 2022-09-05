import java.util.ArrayDeque;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=1475 lang=java
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
    public int[] finalPrices(int[] prices) {
        Deque<Integer> st = new ArrayDeque<>();
        int n = prices.length;
        for (int i = 0; i < n; ++i) {
            while (!st.isEmpty() && prices[st.peekLast()] >= prices[i]) {
                prices[st.pollLast()] -= prices[i];
            }
            st.addLast(i);
        }
        return prices;
    }
}
// @lc code=end
