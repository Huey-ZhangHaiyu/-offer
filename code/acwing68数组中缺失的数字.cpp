/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0到n-1之内。
在范围0到n-1的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
输入：[0,1,2,4]

输出：3
*/
//递增序列，明显用二分
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l=0,r=nums.size()-1;
        
        while(l<r){
            int mid=l+r>>1;
            if(nums[mid]!=mid) r=mid;
            else l=mid+1;
        }
        if(nums[r]==r) r++;//考虑缺失最右边的数的情况
        return r;
    }
};
