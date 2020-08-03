/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。
输入："google"
输出："ggg#ll"
*/

/*如果还用上一题的那种O(n)算法，输入n个数，每次都要n，所以是n^2
优化成O(n)，此题从前往后单调，如果此时的答案在x位，那么说明x之前的字符一定重复
x后面加入新的数字时，答案一定不会在x前面
而且这种队头删除元素，队尾插入元素的双指针结构其实就是队列
*/
class Solution{
public:
    unordered_map<char,int> hash;
    queue<char> q;
    //Insert one char from stringstream
    void insert(char ch){
        hash[ch]++;
        q.push(ch);
        while(q.size()&&hash[q.front()]>1) q.pop();
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        if(q.empty()) return '#';
        return q.front();
    }
};

//优化版，如果插入数字的时候发现次数大于1，那就不用插入了，直接把大于1次的都删掉
class Solution{
public:
    unordered_map<char,int> hash;
    queue<char> q;
    //Insert one char from stringstream
    void insert(char ch){
        if(++hash[ch]>1){
            while(q.size()&&hash[q.front()]>1) q.pop();
        }
        else q.push(ch);//等于1可以插入
        
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        if(q.empty()) return '#';
        return q.front();
    }
};
