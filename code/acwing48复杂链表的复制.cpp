 //请实现一个函数可以复制一个复杂链表
//在复杂链表中，每个结点除了有一个指针指向下一个结点外，还有一个额外的指针指向链表中的任意结点或者null
 /*
 四步走：时间换空间
 1.把链表每一个节点后面插上 一个它本身
 2.把random节点也复制好
 3.把插进去的节点拆出来
 4.复原原来的输入链表
 */
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        for (auto p = head; p;)
        {
            auto np = new ListNode(p->val);//赋值的p
            auto next = p->next;//备份一下原本p的next
            //把np插进去
            p->next = np;
            np->next = next;
            p = next;
        }

        for (auto p = head; p; p = p->next->next)
        {
            if (p->random)//如果当前节点有random指针
                //p的复制p->next的random应该指向p的random指向的复制
                p->next->random = p->random->next;
        }

        auto dummy = new ListNode(-1);//虚拟头
        auto cur = dummy;//遍历指针
        for (auto p = head; p; p = p->next)
        {
            cur->next = p->next;//提取复制点
            cur = cur->next;//cur后移
            p->next = p->next->next;//复原原链表
        }

        return dummy->next;
    }
};

//或者用空间换时间：哈希表
/*
将原链表和新链表的值一一对应
使用hash存储 key = 源链表节点，value = 目标链表节点
遍历源链表，判断每个节点和random节点是否在hash表中，如果不存在则创建
*/
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        unordered_map<ListNode*, ListNode*> hash;
        hash[nullptr] = nullptr;//空hash,hash[NULL]=NULL;
        auto dup = new ListNode(-1), tail = dup;

        while(head)
        {
            if(!hash.count(head)) hash[head] = new ListNode(head->val);//原链表head对应新链表val
            if(!hash.count(head->random)) hash[head->random] = new ListNode(head->random->val);//原链表的random对应新链表的random->val

            tail->next = hash[head];
            tail->next->random = hash[head->random];

            tail = tail->next;
            head = head->next;
        }

        return dup->next;
    }
};
