/*
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] 四叉树交集
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
    Node *intersect(Node *quadTree1, Node *quadTree2) {
        if (quadTree1->isLeaf) {
            if (quadTree1->val) {
                return new Node(true, true);
            } else {
                return quadTree2;
            }
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val) {
                return new Node(true, true);
            } else {
                return quadTree1;
            }
        }
        Node *tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node *tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node *bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node *br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (tl->val == tr->val && tr->val == br->val && bl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            return new Node(tl->val, true);
        } else {
            return new Node(true, false, tl, tr, bl, br);
        }
    }
};
// @lc code=end
