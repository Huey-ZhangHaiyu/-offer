/*
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。
输入：[1,2,3,4,5,6,0]
输出：6
*/
//先自己写一个试试
//双指针暴力做法
class Solution {
public:
    int inversePairs(vector<int>& nums) {
        int i,j;
        int count=0;
        int n=nums.size();
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(nums[i]>nums[j]) count ++;
            }
        }
        return count;
    }
};

//大佬，经典题目
