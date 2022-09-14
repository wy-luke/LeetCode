/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;    //用数组保存单词
        istringstream iss(text); //构造string流
        string word;
        int wordsLen = 0; //全部单词总长度
        while (iss >> word) {
            words.emplace_back(word);
            wordsLen += word.size();
        }

        if (words.size() == 1) {
            return words[0] + string(text.size() - wordsLen, ' ');
        } else {
            // text.size()-wordsLen 为空格总长度
            string space((text.size() - wordsLen) / (words.size() - 1), ' ');

            string ans;
            for (int i = 0; i < words.size() - 1; ++i) {
                ans += words[i] + space;
            }
            ans += words.back();
            ans += string(text.size() - ans.size(), ' ');
            return ans;
        }
    }
};
// @lc code=end
