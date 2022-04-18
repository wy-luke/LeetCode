/*
 * @lc app=leetcode.cn id=2241 lang=cpp
 *
 * [2241] 设计一个 ATM 机器
 */

// @lc code=start
class ATM {
public:
    vector<long> remain;
    vector<int> num{20, 50, 100, 200, 500};
    ATM() {
        remain.resize(5);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            remain[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> v(5); // 记录每种钱取出的个数
        for (int i = 4; i >= 0; --i) {
            long n = min((long)amount / num[i], remain[i]);
            v[i] = (int)n;
            amount -= n * num[i];
        }
        if (amount != 0) {
            return {-1};
        }
        for (int i = 0; i < 5; ++i) {
            remain[i] -= v[i];
        }
        return v;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
// @lc code=end
