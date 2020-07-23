//输入一个链表，反转链表后，输出新链表的表头。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//第一次写
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL){
            return pHead;
        }
        ListNode* p=ReverseList(pHead->next);
        pHead->next ->next=pHead;
        pHead->next=NULL;

        return p;
    }
};

//递归，第二次写
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	//分析极小问题
        if(!head||!head->next) return head;
        //往后递归
        auto p=reverseList(head->next);
        head->next->next=head;//让head的下一个链接到自己
        head->next=NULL;//断开head自己和next的链接
        return p;
    }
};

//迭代，要记录前驱节点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur, cur = next;
        }
        return prev;
    }
};
