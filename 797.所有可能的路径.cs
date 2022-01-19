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
    public IList<IList<int>> AllPathsSourceTarget(int[][] graph)
    {
        List<int> path = new List<int>();
        Traverse(graph, 0, path);
        return res;
    }

    public void Traverse(int[][] graph, int s, List<int> path)
    {
        path.Add(s);

        if (s == graph.Length - 1)
        {
            res.Add(new List<int>(path));
            path.RemoveAt(path.Count - 1);
            return;
        }

        foreach (int i in graph[s])
        {
            Traverse(graph, i, path);
        }

        path.RemoveAt(path.Count - 1);
    }
}
// @lc code=end

