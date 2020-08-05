//输入两个链表，找出它们的第一个公共结点。

/*先获得两个链表的长度，然后在较长的链表上先走若干步(两链表长度之差)
接着同时在两个链表上遍历，找到的第一个相同的节点就是他们的第一个公共节点
时间复杂度O(m + n)。
*/
//第二次写
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return nullptr;
        auto i=headA,j=headB;
        int l1=0,l2=0;
        while(i){
            i=i->next;
            l1++;
        }
        while(j){
            j=j->next;
            l2++;
        }
        i=headA,j=headB;
        if(l1<l2){
            for(int x=0;x<l2-l1;x++) j=j->next;
        }
        else if(l1>l2){
            for(int x=0;x<l1-l2;x++) i=i->next;
        }
        while(i!=j){//如果没有公共节点，ij会一直走到null
                i=i->next;
                j=j->next;
            }
        return i;
    }
};
//大佬的想法
/*
假设两条链表长度分别为:a+c和b+c
让i走完第一条节点的时候，接着走第二条链表，j走完第二条链表的时候接着走第一条
那么i走过a+c+b的时候，j走完了b+c+a，两指针刚好相遇在第一个公共节点
*/
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto i=headA,j=headB;
        while(i!=j){
            if(i) i=i->next;
            else i=headB;
            if(j) j=j->next;
            else j=headA;
        }
        return i;
};
