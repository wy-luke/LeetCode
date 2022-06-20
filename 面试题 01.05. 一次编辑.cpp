class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first == second) return true;
        int m = first.size(), n = second.size();
        if (abs(m - n) > 1) return false;
        if (m == n) {
            for (int i = 0; i < m; ++i) {
                if (first[i] != second[i] && first.substr(i + 1) != second.substr(i + 1)) return false;
            }
        } else if (m < n) {
            for (int i = 0; i < m; ++i) {
                if (first[i] != second[i] && first.substr(i) != second.substr(i + 1)) return false;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (first[i] != second[i] && first.substr(i + 1) != second.substr(i)) return false;
            }
        }
        return true;
    }
};