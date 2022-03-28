/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
private:
    vector<int> nums;                   // 存储数据
    unordered_map<int, int> valToIndex; // 记录 值 和 index
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (valToIndex.count(val) != 0) {
            return false;
        } else {
            nums.emplace_back(val);
            // 由于先往 vector 里添加 val，所以 index 为 size - 1
            valToIndex.emplace(val, nums.size() - 1);
            return true;
        }
    }

    bool remove(int val) {
        if (valToIndex.count(val) == 0) {
            return false;
        } else {
            int n = nums.size();

            // 哈希表中把最后一个数对应的 index 改为要删除的数的 index
            valToIndex[nums[n - 1]] = valToIndex[val];
            // 把 要删除的数 赋值为 最后一个数，即实现换位
            nums[valToIndex[val]] = nums[n - 1];
            // 哈希表中删除 val 的索引
            valToIndex.erase(val);
            // vector 中删除最后一个数
            nums.pop_back();

            return true;
        }
    }

    int getRandom() {
        // rand % max 生成 [0, max) 范围的随机数
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
