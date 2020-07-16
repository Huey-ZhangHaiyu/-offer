//给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。
//请找出数组中任意一个重复的数，但不能修改输入的数组。
//只能使用 O(1) 的额外空间,也就是不能创建新的数组

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l=1;
        while(l<r){
        int r=nums.size()-1;
        int mid=l+r>>1;
        int count = 0;
        for(auto x:nums){
            if(x>0&&x<=mid) count++;
        }
        if(count>mid+l-1) r=mid;
        else l=mid+1;
        }
        return r;
    }
};
