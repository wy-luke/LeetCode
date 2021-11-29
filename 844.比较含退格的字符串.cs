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
        if (ProcessString(s) == ProcessString(t))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    private string ProcessString(string str)
    {
        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] == '#')
            {
                if (i == 0)
                {
                    str = str.Remove(0, 1);
                    i--;
                }
                else
                {
                    str = str.Remove(i - 1, 2);
                    i = i - 2;
                }
            }
        }
        return str;
    }
}
// @lc code=end

