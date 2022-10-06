/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> mp;
        for (string &cpdomain : cpdomains) {
            int spaceIdx = cpdomain.find(" ");
            int cnt = stoi(cpdomain.substr(0, spaceIdx));
            cpdomain = cpdomain.substr(spaceIdx + 1);
            mp[cpdomain] += cnt;
            int dot = cpdomain.find(".");
            if (dot != string::npos) {
                mp[cpdomain.substr(dot + 1)] += cnt;
                dot = cpdomain.find(".", dot + 1);
                if (dot != string::npos) {
                    mp[cpdomain.substr(dot + 1)] += cnt;
                }
            }
        }
        vector<string> ans;
        for (const auto &[k, v] : mp) {
            ans.push_back(to_string(v) + " " + k);
        }
        return ans;
    }
};
// @lc code=end
