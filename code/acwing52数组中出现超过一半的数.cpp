/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
假设数组非空，并且一定存在满足条件的数字。

假设要求只能使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？
*/
/*
妙阿！
找一个计数器cnt记录数x的个数，遇到y的时候cnt--
cnt=0时换数，如果已知有个数一定多于一半，那么只要遇到不同的数就让计数器减一
最后剩下的数一定是那个数
*/
class Solution {
public:
    int val;
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int cnt=1;
        val=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==val) cnt++;
            else{ 
                cnt--;
                if(cnt==0) {
                    val=nums[i];
                    cnt=1;
                }
            }
        }
        return val;
    }
};
