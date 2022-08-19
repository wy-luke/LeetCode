
/*
 * @lc app=leetcode.cn id=1450 lang=java
 *
 * [1450] 在既定时间做作业的学生人数
 */
import java.util.*;

// @lc code=start
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        Arrays.sort(startTime);
        Arrays.sort(endTime);

        int l = 0, r = startTime.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (startTime[mid] <= queryTime) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int tmp = l;

        l = 0;
        r = endTime.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (endTime[mid] < queryTime) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return tmp - l;
    }
}
// @lc code=end
