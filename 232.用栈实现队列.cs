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
    int front;

    public MyQueue()
    {
        stack1 = new Stack<int>();
        stack2 = new Stack<int>();
    }


    // Stack1为队列倒序（先进后出），Stack2为队列序（先进先出）。
    // Stack1先出的为第一个入栈的，Stack2先出的为最上面的，即栈的Peek。
    // 定义front记录Stack1应先出的元素，用于队列的Peek
    public void Push(int x)
    {
        if (stack1.Count == 0)
        {
            front = x;
        }
        stack1.Push(x);
    }

    // Stack2的顶部元素为整体的先出元素，如果Stack2不为空，将Stack2顶部元素弹出即可
    // 如果Stack2为空，则将Stack1依次弹入Stack2，再将Stack2顶部元素弹出
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

    // 当Stack2不为空时，Stack2的顶部元素为整体的先出元素
    // 当Stack2为空时，Stack1的front为整体的先出元素
    public int Peek()
    {
        if (stack2.Count == 0)
        {
            return front;
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

