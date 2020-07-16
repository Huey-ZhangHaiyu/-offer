//给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。
//请找出数组中任意一个重复的数，但不能修改输入的数组。
//只能使用 O(1) 的额外空间,也就是不能创建新的数组
/*
思路：n个数值范围，但是有n+1个数，必然有两个数字相同
那么把1-n分成两份，如果数组中小于n/2的数多于n/2个，那么1-n/2的区间中一定有数字重复
抽屉和分治思想
*/
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l=1,r=nums.size();//数值范围1-n
        while(l<r){
            int mid=l+r>>1;
            int count = 0;
            for(auto x:nums){
                if(x>0&&x<=mid) count++;//找出小于mid的个数
            }
            if(count>mid+l-1) r=mid;
            else l=mid+1;
        }
        return r;
    }
};
