/*
 * @lc app=leetcode.cn id=5 lang=csharp
 *
 * [5] 最长回文子串
 */

// @lc code=start
public class Solution
{
    public string LongestPalindrome(string s)
    {
        string res = "";
        for (int i = 0; i < s.Length; ++i)
        {
            string res1 = Palindrome(s, i, i);
            string res2 = Palindrome(s, i, i + 1);
            res = res.Length > res1.Length ? res : res1;
            res = res.Length > res2.Length ? res : res2;
        }
        return res;
    }

    string Palindrome(string s, int l, int r)
    {
        while (l >= 0 && r <= s.Length - 1 && s[l] == s[r])
        {
            --l;
            ++r;
        }
        return s.Substring(l + 1, r - l - 1);
    }
}
// @lc code=end

