/*
 * @lc app=leetcode.cn id=844 lang=csharp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
public class Solution
{
    public bool BackspaceCompare(string s, string t)
    {
        int sl = s.Length - 1, tl = t.Length - 1;
        int sSkip = 0, tSkip = 0;
        while (sl >= 0 || tl >= 0)
        {
            while (sl >= 0)
            {
                if (s[sl] == '#')
                {
                    sSkip++;
                    sl--;
                }
                else if (sSkip > 0)
                {
                    sSkip--;
                    sl--;
                }
                else
                {
                    break;
                }
            }
            while (tl >= 0)
            {
                if (t[tl] == '#')
                {
                    tSkip++;
                    tl--;
                }
                else if (tSkip > 0)
                {
                    tSkip--;
                    tl--;
                }
                else
                {
                    break;
                }
            }
            if (sl >= 0 && tl >= 0)
            {
                if (t[tl] != s[sl])
                {
                    return false;
                }
            }
            else if (sl >= 0 || tl >= 0)
            {
                return false;
            }
            sl--;
            tl--;
        }
        return true;
    }
}
// @lc code=end

