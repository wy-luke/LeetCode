/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

// @lc code=start
class OrderedStream {
private:
    vector<string> stream;
    int ptr = 0;

public:
    OrderedStream(int n) {
        stream.resize(n);
    }

    vector<string> insert(int idKey, string value) {
        stream[idKey - 1] = value;
        if (!stream[ptr].empty()) {
            vector<string> ans;
            while (ptr < stream.size() && !stream[ptr].empty()) {
                ans.emplace_back(stream[ptr++]);
            }
            return ans;
        }
        return {};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end
