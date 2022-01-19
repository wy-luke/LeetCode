/*
 * @lc app=leetcode.cn id=797 lang=csharp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
public class Solution
{
    // 记录所有路径
    IList<IList<int>> res = new List<IList<int>>();
    List<int> path = new List<int>();
    public IList<IList<int>> AllPathsSourceTarget(int[][] graph)
    {
        path.Add(0);
        Traverse(graph, 0, graph.Length - 1);
        return res;
    }

    public void Traverse(int[][] graph, int s, int n)
    {
        if (s == n)
        {
            res.Add(new List<int>(path));
            return;
        }

        foreach (int i in graph[s])
        {
            path.Add(i);
            Traverse(graph, i, graph.Length - 1);
            path.RemoveAt(path.Count - 1);
        }
    }
}
// @lc code=end

