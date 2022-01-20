/*
 * @lc app=leetcode.cn id=210 lang=csharp
 *
 * [210] 课程表 II
 */

// @lc code=start
public class Solution
{
    public bool[] visited;
    public bool[] onPath;
    public bool hasCycle;
    public List<int> postOrder;
    public int[] FindOrder(int numCourses, int[][] prerequisites)
    {
        visited = new bool[numCourses];
        onPath = new bool[numCourses];
        postOrder = new List<int>();

        List<int>[] graph = BuildGraph(numCourses, prerequisites);

        for (int i = 0; i < graph.Length; ++i)
        {
            Traverse(graph, i);
        }

        if (hasCycle) return new int[] { };

        postOrder.Reverse();

        return postOrder.ToArray();
    }

    public void Traverse(List<int>[] graph, int s)
    {
        if (onPath[s]) hasCycle = true;

        if (visited[s] || hasCycle) return;

        visited[s] = true;
        onPath[s] = true;
        foreach (int i in graph[s])
        {
            Traverse(graph, i);
        }
        onPath[s] = false;
        postOrder.Add(s);
    }

    public List<int>[] BuildGraph(int numCourses, int[][] prerequisites)
    {
        List<int>[] graph = new List<int>[numCourses];
        for (int i = 0; i < graph.Length; ++i)
        {
            graph[i] = new List<int>();
        }

        foreach (int[] i in prerequisites)
        {
            graph[i[1]].Add(i[0]);
        }

        return graph;
    }
}
// @lc code=end

