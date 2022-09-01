/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        stack<int> st;
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.emplace(i);
        }
        return prices;
    }
};

class Solution2 {
public:
    vector<int> finalPrices(vector<int> &prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.emplace(prices[i]);
        }
        return ans;
    }
};

class Solution3 {
public:
    vector<int> finalPrices(vector<int> &prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? prices[i] : prices[i] - prices[st.top()];
            st.emplace(i);
        }
        return ans;
    }
};
