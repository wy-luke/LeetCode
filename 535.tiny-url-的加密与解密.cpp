/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */

// @lc code=start
class Solution {
public:
    string strs = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";
    string pre = "http://tinyurl.com/";
    unordered_map<string, string> t2o, o2t;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (!o2t.count(longUrl)) {
            string s;
            while (t2o.count(s)) {
                s = "";
                for (int i = 0; i < 6; ++i) s.push_back(strs[rand() % strs.size()]);
                s = pre + s;
            }
            o2t[longUrl] = s;
            t2o[s] = longUrl;
        }
        return o2t[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return t2o[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
