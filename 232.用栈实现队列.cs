/*
 * @lc app=leetcode.cn id=232 lang=csharp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
public class MyQueue
{
    Stack<int> stack1;
    Stack<int> stack2;

    public MyQueue()
    {
        stack1 = new Stack<int>();
        stack2 = new Stack<int>();
    }

    public void Push(int x)
    {
        if (stack2.Count == 0)
        {
            stack1.Push(x);
        }
        else
        {
            while (stack2.Count > 0)
            {
                stack1.Push(stack2.Pop());
            }
            stack1.Push(x);
        }

    }

    public int Pop()
    {
        if (stack2.Count == 0)
        {
            while (stack1.Count > 0)
            {
                stack2.Push(stack1.Pop());
            }
            return stack2.Pop();
        }
        else
        {
            return stack2.Pop();
        }

    }

    public int Peek()
    {
        if (stack2.Count == 0)
        {
            while (stack1.Count > 0)
            {
                stack2.Push(stack1.Pop());
            }
            return stack2.Peek();
        }
        else
        {
            return stack2.Peek();
        }
    }

    public bool Empty()
    {
        if (stack1.Count == 0 && stack2.Count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Peek();
 * bool param_4 = obj.Empty();
 */
// @lc code=end

