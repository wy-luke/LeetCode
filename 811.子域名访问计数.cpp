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
            int dot1 = cpdomain.find_first_of(".");
            int dot2 = cpdomain.find_last_of(".");
            mp[cpdomain] += cnt;
            if (dot1 != string::npos && dot1 != dot2) {
                mp[cpdomain.substr(dot2 + 1)] += cnt;
                mp[cpdomain.substr(dot1 + 1)] += cnt;
            } else if (dot1 == dot2 && dot1 != string::npos) {
                mp[cpdomain.substr(dot1 + 1)] += cnt;
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
