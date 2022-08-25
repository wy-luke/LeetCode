import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=658 lang=java
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n = arr.length;
        int idx = bs(arr, x);
        int l = idx - 1, r = idx;
        while (r - l - 1 < k) {
            if (l < 0) {
                ++r;
            } else if (r >= n) {
                --l;
            } else {
                if (Math.abs(arr[l] - x) <= Math.abs(arr[r] - x)) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = l + 1; i < r; ++i) {
            ans.add(arr[i]);
        }
        return ans;
    }

    private int bs(int[] arr, int x) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}
// @lc code=end
