//定义两个指针f，s，分别速度为2和1
//那么两指针同时从头出发一定会相遇于环内
//假设链表非环部分长度为a，环长为b
//两指针速度差为1，所以s进入环的时候，f已经在环中走了a
//这个时候相当于f每次追s 1个单位，两者差了(b-a)距离
//所以两者相遇的时候，s在环里走了(b-a)，也就是距离环出口a的地方
//让一个指针在相遇点，另一个指针从头出发，速度相同，相遇点即为入口

//第一次写
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL|| 
           pHead->next==NULL||
           pHead->next->next==NULL) return NULL;
        ListNode* fast=pHead->next->next;//注意这里的初始
        ListNode* slow=pHead->next;
        while(fast->val!=slow->val){
            if(fast->next!=NULL&&fast->next->next!=NULL){//判断是否有环
                fast=fast->next->next;
                slow=slow->next;
            }
            else return NULL;
        }
        slow=pHead;//slow指针回起始点
        while(fast->val!=slow->val){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};

//第二次写
class Solution {
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        if(!head||!head->next||!head->next->next) return NULL;
        auto s=head->next,f=head->next->next;
        while(s->val!=f->val){
            if(!f->next||!f->next->next) return NULL;
            else{
                s=s->next;
                f=f->next->next;
            }
        }
        s=head;
        while(s->val!=f->val){
            s=s->next;
            f=f->next;
        }
        return f;
    }
};

//第三次
class Solution {
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        auto i=head;
        auto j=head;
        while(j&&j->next){
            i=i->next;
            j=j->next->next;
            if(i==j){
                i=head;
                while(i!=j){
                    i=i->next;
                    j=j->next;
                }
            return i;
            }
        }
        return 0;
    }
};
