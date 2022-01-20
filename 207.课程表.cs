/*
 * @lc app=leetcode.cn id=207 lang=csharp
 *
 * [207] 课程表
 */

// @lc code=start
public class Solution
{
    public bool[] visited;
    public bool[] onPath;
    public bool hasCycle = false;
    public bool CanFinish(int numCourses, int[][] prerequisites)
    {
        visited = new bool[numCourses];
        onPath = new bool[numCourses];
        List<int>[] graph = BuildGraph(numCourses, prerequisites);

        for (int i = 0; i < numCourses; ++i)
        {
            Traverse(graph, i);
        }
        return !hasCycle;
    }

    public void Traverse(List<int>[] graph, int s)
    {
        if (onPath[s]) hasCycle = true;

        if (visited[s] || hasCycle)
        {
            return;
        }

        visited[s] = true;

        onPath[s] = true;
        foreach (int g in graph[s])
        {
            Traverse(graph, g);
        }
        onPath[s] = false;
    }

    public List<int>[] BuildGraph(int numCourses, int[][] prerequisites)
    {
        List<int>[] graph = new List<int>[numCourses];

        for (int i = 0; i < graph.Length; ++i)
        {
            graph[i] = new List<int>();
        }

        foreach (int[] edge in prerequisites)
        {
            graph[edge[1]].Add(edge[0]);
        }

        return graph;
    }
}
// @lc code=end

