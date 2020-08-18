//给定单向链表的一个节点指针，定义一个函数在O(1)时间删除该结点。
//假设链表一定存在，并且该节点一定不是尾节点。
//输入：链表 1->4->6->8
//删掉节点：第2个节点即6（头节点为第0个节点）
//输出：新链表 1->4->8
/*
思路很巧妙，因为没有前驱节点，又要求O(1)，且后续节点一定不为NULL
所以让后续节点的值覆盖当前节点，然后删除后续节点即可
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;//这两句有更狠的做法
        node->next=node->next->next;//写成这样：*node = *(node->next);
    }
};
