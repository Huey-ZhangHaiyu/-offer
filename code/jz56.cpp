//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
