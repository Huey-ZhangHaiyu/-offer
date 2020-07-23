//输入一个链表，输出该链表中倒数第k个结点。

//自己写的
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int l=1;//记录链表长度
        auto p=head;
        while(head->next){
            l++;
            head=head->next;
        }
        if(l<k) return NULL;
        for(int i=0;i<l-k;i++){
            p=p->next;
        } 
        return p;
    }
};

//大佬的答案
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n < k) return nullptr;
        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        return p;
    }
};
