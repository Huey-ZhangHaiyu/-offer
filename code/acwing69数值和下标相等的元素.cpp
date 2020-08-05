/*
假设一个单调递增的数组里的每个元素都是整数并且是唯一的。
请编程实现一个函数找出数组中任意一个数值等于其下标的元素。

样例
输入：[-3, -1, 1, 3, 5]
输出：3
注意:如果不存在，则返回-1。
*/

class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(nums[mid]<mid) l=mid+1;
            else if(nums[mid]>mid) r=mid-1;
            else return mid;
        }
        if(nums[r]!=r) return -1;
        return r;
    }
};
