/*
给定一个单链表，请使用快速排序算法对其排序。
要求：期望平均时间复杂度为 O(nlogn)，期望额外空间复杂度为 O(logn)。
思考题： 如果只能改变链表结构，不能修改每个节点的val值该如何做呢？
*/

/*
快排的思路就是找到一个中间值，让左边都小于中间值，右边大于中间值，使得左中右先是顺序的
接着递归左右两边即可
那么在链表中，搞出三个指针即可进行划分
left,mid,right
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
    ListNode* get_tail(ListNode* head) {
        while (head->next) head = head->next;
        return head;
    }

    ListNode* quickSortList(ListNode* head) {
        if (!head || !head->next) return head;

        auto left = new ListNode(-1), mid = new ListNode(-1), right = new ListNode(-1);
        auto ltail = left, mtail = mid, rtail = right;
        int val = head->val;

        for (auto p = head; p; p = p->next) {
            if (p->val < val) ltail = ltail->next = p;//注意这里要更新ltail位置
            else if (p->val == val) mtail = mtail->next = p;
            else rtail = rtail->next = p;
        }

        ltail->next = mtail->next = rtail->next = NULL; //注意这里！！！！！
        left->next = quickSortList(left->next);
        right->next = quickSortList(right->next);

        // 拼接三个链表
        get_tail(left)->next = mid->next;
        get_tail(left)->next = right->next;

        // auto p = left->next;
        // delete left;
        // delete mid;
        // delete right;
        return left->next;
    }
};
