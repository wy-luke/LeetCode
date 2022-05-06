/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> preSum(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        return helper(preSum, 0, n - 1, 0, n - 1);
    }

    Node *helper(vector<vector<int>> &preSum, int rowStart, int rowEnd, int colStart, int colEnd) {
        int sum = preSum[rowEnd + 1][colEnd + 1] - preSum[rowStart][colEnd + 1] - preSum[rowEnd + 1][colStart] +
                  preSum[rowStart][colStart];

        if (sum == 0 || sum == (rowEnd - rowStart + 1) * (colEnd - colStart + 1)) return new Node(sum == 0 ? 0 : 1, true);

        return new Node(1,
                        false,
                        helper(preSum, rowStart, (rowEnd + rowStart) / 2, colStart, (colEnd + colStart) / 2),
                        helper(preSum, rowStart, (rowEnd + rowStart) / 2, (colEnd + colStart) / 2 + 1, colEnd),
                        helper(preSum, (rowEnd + rowStart) / 2 + 1, rowEnd, colStart, (colEnd + colStart) / 2),
                        helper(preSum, (rowEnd + rowStart) / 2 + 1, rowEnd, (colEnd + colStart) / 2 + 1, colEnd));
    }
};
// @lc code=end
