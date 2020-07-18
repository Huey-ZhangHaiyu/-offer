//jz03 reverse a linked list
//stack solution
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

//recrusion
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
    vector<int> temp;
    vector<int> printListReversingly(ListNode* head) {
        if(head){//head空的话，pushback的参数就无效了；
            if(head->next){
            printListReversingly(head->next);
            }
            temp.push_back(head->val);
        }
        return temp;
    }
};

//反向迭代器
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};

//反向迭代器输出逆序遍历
vector<int>::reverse_iterator iter = vecInt.rbegin();
for (; iter != vecInt.rend(); ++iter)
{
	cout << *iter << endl;
}
