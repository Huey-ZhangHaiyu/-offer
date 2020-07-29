/*输入一个 非空 整型数组，数组里的数可能为正，也可能为负。
求所有子数组的和的最大值。
要求时间复杂度为O(n)。*/
/*
老经典了
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN,s=0;//res不能初始化为0，否则数组全负数的情况不对
        for(auto x:nums){
            s+=x;
            if(s>res) res=s;
            if(s<=0) s=0;
        }
        return res;
    }
};
