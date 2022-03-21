class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> updates) {
        vector<int> res(length);
        for (vector<int> update : updates) {
            res[updates[0]] += updates[2];
            if (updates[1] + 1 < length) {
                res[updates[1] + 1] -= updates[2];
            }
        }
        for (int i = 1; i < length; ++i) {
            res[i] = res[i - 1] + res[i];
        }
        return res;
    }
};