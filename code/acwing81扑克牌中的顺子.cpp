/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，大小王可以看做任意数字。
为了方便，大小王均以0来表示，并且假设这副牌中大小王均有两张。
*/

/*
删去所有的0
判断一下剩下的数字是不是重复
判断一下剩下的数字最大值和最小值之间的差距是不是小于5
*/
class Solution {
public:
    bool isContinuous(vector<int> nums) {
        if(nums.empty()) return false;
        sort(nums.begin(),nums.end());
        int p=0;
        while(!nums[p]) p++;
        
        int i=p;
        while(i+1<nums.size()){
            if(nums[i]==nums[i+1]) return false;
            i++;
        }
        if(nums[i]-nums[p]<5) return true;
        return false;
    }
};
