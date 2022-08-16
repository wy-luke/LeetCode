import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1656 lang=java
 *
 * [1656] 设计有序流
 */

// @lc code=start
class OrderedStream {
    private int ptr = 0;
    private String[] stream;

    public OrderedStream(int n) {
        stream = new String[n];
    }

    public List<String> insert(int idKey, String value) {
        stream[idKey - 1] = value;
        List<String> ans = new ArrayList<>();
        if (stream[ptr] != null) {
            while (ptr < stream.length && stream[ptr] != null) {
                ans.add(stream[ptr++]);
            }
            return ans;
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */
// @lc code=end
