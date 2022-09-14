/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int n = quality.size();
        vector<int> idx(n);
        // 构建递增数组，代表每个工人的下标
        iota(idx.begin(), idx.end(), 0);
        // 按照 工人单位质量所需工资 由便宜到更贵 来排序
        sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
            return wage[a] * quality[b] < wage[b] * quality[a];
        });
        int sumq = 0;
        priority_queue<int> pq; // 大顶堆
        // 先取 单位质量工资 最便宜的前 k 个工人
        for (int i = 0; i < k; ++i) {
            pq.push(quality[idx[i]]);
            sumq += quality[idx[i]];
        }
        // 此时是按照第 k 个工人的 单位质量工资 发工资，总质量为 sumq
        double sumc = sumq * ((double)wage[idx[k - 1]] / quality[idx[k - 1]]);
        // 按 单位质量工资 顺序枚举所有工人
        for (int i = k; i < n; ++i) {
            // 由于 sumc = sumq * 当前最高单位质量工资;
            // 单位质量工资 是增加的，所以当 sumq 下降时，sumc 才有可能下降
            if (quality[idx[i]] < pq.top()) {
                sumq -= pq.top();
                sumq += quality[idx[i]];
                pq.pop();
                pq.push(quality[idx[i]]);

                sumc = min(sumc, sumq * ((double)wage[idx[i]] / quality[idx[i]]));
            }
        }
        return sumc;
    }
};
// @lc code=end
