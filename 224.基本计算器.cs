public class Solution
{

    public int Calculate(string s)
    {
        // 记录数字
        Stack<string> numbers = new Stack<string>();
        // 记录符号
        Stack<char> symbols = new Stack<char>();
        // 记录符号的数量，用以判断多位数结束
        int symbolCount = -1;
        // 记录数字的数量，用以判断多位数结束
        int numberCount = 0;
        int m, n;
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }

            if (s[i] == '+' || s[i] == '-')
            {
                if (numberCount != 0)
                {
                    n = Int32.Parse(numbers.Pop());
                    m = Int32.Parse(numbers.Pop());
                    if (symbols.Pop() == '+')
                    {
                        numbers.Push((m + n).ToString());
                    }
                    else
                    {
                        numbers.Push((m + n).ToString());
                    }
                }

                symbols.Push(s[i]);
            }
            else
            {
                if (symbolCount == symbols.Count)
                {

                }
                else
                {
                    numbers.Push(s[i].ToString());
                    symbolCount = symbols.Count;
                }
            }

        }
        n = Int32.Parse(numbers.Pop());
        m = Int32.Parse(numbers.Pop());
        if (symbols.Pop() == '+')
        {
            numbers.Push((m + n).ToString());
        }
        else
        {
            numbers.Push((m + n).ToString());
        }
        return Int32.Parse(numbers.Pop());
    }
}
// @lc code=end

/*
 * @lc app=leetcode.cn id=224 lang=csharp
 *
 * [224] 基本计算器
 */

// @lc code=start

