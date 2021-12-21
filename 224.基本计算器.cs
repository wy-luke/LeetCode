/*
 * @lc app=leetcode.cn id=224 lang=csharp
 *
 * [224] 基本计算器
 */

// @lc code=start
public class Solution
{
    private int i = 0;

    public int Calculate(string s)
    {
        Stack<int> stk = new Stack<int>();
        int num = 0;
        char sign = '+';

        for (; i < s.Length; ++i)
        {
            if (Char.IsDigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] == '(')
            {
                ++i;
                num = Calculate(s);
            }
            if ((!Char.IsDigit(s[i]) && s[i] != ' ') || i == s.Length - 1)
            {
                switch (sign)
                {
                    case '+':
                        stk.Push(num);
                        break;
                    case '-':
                        stk.Push(-num);
                        break;
                    case '*':
                        stk.Push(stk.Pop() * num);
                        break;
                    case '/':
                        stk.Push(stk.Pop() / num);
                        break;
                }

                num = 0;
                sign = s[i];
            }
            if (s[i] == ')')
            {
                if (i != s.Length - 1) ++i;
                break;
            }
        }

        int res = 0;
        while (stk.Count != 0)
        {
            res += stk.Pop();
        }
        return res;
    }
}
// @lc code=end

