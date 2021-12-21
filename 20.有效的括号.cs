/*
 * @lc app=leetcode.cn id=20 lang=csharp
 *
 * [20] 有效的括号
 */

// @lc code=start
public class Solution
{
    public bool IsValid(string s)
    {
        Stack<char> symbols = new Stack<char>();
        Dictionary<char, char> pair = new Dictionary<char, char>(){
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        foreach (char symbol in s)
        {
            if ("({[".Contains(symbol))
            {
                symbols.Push(symbol);
            }
            else
            {
                if (symbols.Count == 0)
                {
                    return false;
                }

                if (symbol == pair[symbols.Peek()])
                {
                    symbols.Pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if (symbols.Count() == 0) return true;
        return false;
    }
}
// @lc code=end

