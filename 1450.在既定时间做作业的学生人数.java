
/*
 * @lc app=leetcode.cn id=1450 lang=java
 *
 * [1450] 在既定时间做作业的学生人数
 */
import java.util.*;

// @lc code=start
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int maxEnd = Arrays.stream(endTime).max().getAsInt();
        if (queryTime > maxEnd) return 0;
        int[] cnt = new int[maxEnd + 2];
        for (int i = 0; i < startTime.length; ++i) {
            cnt[startTime[i]]++;
            cnt[endTime[i] + 1]--;
        }
        int ans = 0;
        for (int i = 0; i <= queryTime; ++i) {
            ans += cnt[i];
        }
        return ans;
    }
}
// @lc code=end
