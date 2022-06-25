class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int dp1 = costs[0][0], dp2 = costs[0][1], dp3 = costs[0][2];
        for (int i = 1; i < costs.size(); ++i) {
            int ndp1 = min(dp2, dp3) + costs[i][0];
            int ndp2 = min(dp1, dp3) + costs[i][1];
            int ndp3 = min(dp1, dp2) + costs[i][2];
            dp1 = ndp1;
            dp2 = ndp2;
            dp3 = ndp3;
        }
        return min({dp1, dp2, dp3});
    }
};