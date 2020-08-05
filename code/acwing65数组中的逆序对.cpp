/*
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。
输入：[1,2,3,4,5,6,0]
输出：6
*/
//先自己写一个试试
//双指针暴力做法O(n^2)
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
/*
首先想到的暴力一定不是面试官想要的，比暴力更快一点的复杂度为nlogn，怎么才会有logn出现呢
一半一半就会有logn出现，用归并排序顺便解决这个问题
归并排序拆成左右两个区间，那么存在的逆序对就是左边的逆序+右逆序+跨越区间的逆序
又因为归并排序的递归过程中，左右两段都是单调的，且两个内部的逆序对都已经算过了，只需要算当前状态的逆序对就行了，不会重复的
所以当左边的i得到nums[i]比右边找到的nums[j]大的时候，左边i之后的数也一定比nums[j]大
此时针对nums[j]一个数的跨区间逆序对个数即为mid-i+1；
*/
class Solution {
public:
    int inversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);    
    }
    
    int merge(vector<int>& nums,int l,int r){
        if(l>=r) return 0;
        int mid=l+r>>1;
        int res=merge(nums,l,mid)+merge(nums,mid+1,r);//先把左右单独的逆序对算出来
        
        int i=l,j=mid+1;
        vector<int> temp;//记录排序结果
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]) temp.push_back(nums[i++]);//一直在两边找
            else{//直到找到左边比右边大的
                temp.push_back(nums[j++]);
                res+=mid-i+1;//记一下针对此时nums[j]出现的跨区间逆序对
            }        
        }
        while(i<=mid) temp.push_back(nums[i++]);//把后面的接上
        while(j<=r) temp.push_back(nums[j++]);
        
        i=l;
        for(auto x:temp) nums[i++]=x;//将排序后的结果给回nums
        
        return res;
    }
};
