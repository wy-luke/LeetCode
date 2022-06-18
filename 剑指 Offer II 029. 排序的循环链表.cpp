/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        // 先创建要插入的节点
        Node *node = new Node(insertVal);
        node->next = node;
        if (head == nullptr) return node;
        // 备份 head 节点
        Node *res = head;
        // 依次检查每个节点，看 node 能否插入到该节点后面
        do {
            // 节点处于递增时
            if (head->val <= insertVal && insertVal <= head->next->val) {
                node->next = head->next;
                head->next = node;
                return res;
            }
            // 节点处于有序的截断点时，如果插入值比链表尾部元素大 或 比首部元素小，插入
            if (head->val > head->next->val && ((head->val > insertVal && insertVal <= head->next->val) || (head->val <= insertVal && insertVal > head->next->val))) {
                node->next = head->next;
                head->next = node;
                return res;
            }
            head = head->next;
        } while (head != res);
        // 到这里循环一圈了，还没插入，表示链表所有元素都相同，且插入值不同，则随便插即可
        head->next = new Node(insertVal, head->next);
        return res;
    }
};