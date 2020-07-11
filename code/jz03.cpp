//jz03 reverse a linked list
//stack solution
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> value;
        ListNode *p=NULL;
        p=head;
        stack<int> stk;
        while(p!=NULL){
            stk.push(p->val);
            p=p->next;
        }
        while(!stk.empty()){
            value.push_back(stk.top());
            stk.pop();
        }
        return value;
    }
};

//recrusion
class Solution {
public:
    vector<int> value;
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p=NULL;
        p=head;
        if(p!=NULL){
            if(p->next!=NULL){
                printListFromTailToHead(p->next);
            }
            value.push_back(p->val);
        }
        return value;            
        }
};
