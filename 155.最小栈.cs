/*
 * @lc app=leetcode.cn id=155 lang=csharp
 *
 * [155] 最小栈
 */

// @lc code=start
public class MinStack
{
    Stack<(int, int)> theStack;

    public MinStack()
    {
        theStack = new Stack<(int, int)>();
    }

    public void Push(int val)
    {
        if (theStack.Count == 0)
        {
            theStack.Push((val, val));
        }
        else
        {
            if (val < theStack.Peek().Item2)
            {
                theStack.Push((val, val));
            }
            else
            {
                theStack.Push((val, theStack.Peek().Item2));
            }
        }
    }

    public void Pop()
    {
        theStack.Pop();
    }

    public int Top()
    {
        return theStack.Peek().Item1;
    }

    public int GetMin()
    {
        return theStack.Peek().Item2;
    }
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */
// @lc code=end