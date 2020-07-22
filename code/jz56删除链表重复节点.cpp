//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

//看成一个一个的段，需要删除长度大于1的段
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* dummy=new ListNode(-1);//凡是有可能删除头节点的问题，我们都要设置一个虚拟头节点
        dummy->next=head;//这样就不会担心头节点被删除的情况
        
        ListNode*p=dummy;//p是指向上一个不重复的段尾的指针
        while(p->next){
            ListNode* q=p->next;//q指针用于遍历下一个段
            //不能写成(p->next->val==q->val&&q)因为条件表达式从左到右执行，如果q不存在，q->val报错
            while(q&&p->next->val==q->val) q=q->next;//把q跳过下一个段
            if(p->next->next==q) p=p->next;//如果下个段长度为1，则把p和p->next接在一起
            else p->next=q;//如果下个段长度大于1，则把p和q接在一起
        }
        return dummy->next;//返回头节点即可
        delete dummy;
    }
};

//递归思路就是：
/*
1.当前值和下一个比较，相同的话就一直往后找到不同为止，返回不同的那个数，并代入下一次递归
2.当前值和下一个不同的话，把当前的next作为下次输入的参数（作为下一次的当前指针），并把当前next指向返回值
*/
class Solution {//这是一个排序的链表！！
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
         if (pHead==NULL)
            return NULL;
        if (pHead!=NULL && pHead->next==NULL)
            return pHead;
                 
        ListNode* current;
         
        if ( pHead->next->val==pHead->val){
            current=pHead->next->next;
            while (current != NULL && current->val==pHead->val)
                current=current->next;
            return deleteDuplication(current);                     
        }
         
        else {
            current=pHead->next;
            pHead->next=deleteDuplication(current);
            return pHead;
        }    
    }
};
