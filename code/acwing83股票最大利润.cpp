/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖 一次 该股票可能获得的利润是多少？
例如一只股票在某些时间节点的价格为[9, 11, 8, 5, 7, 12, 16, 14]。
如果我们能在价格为5的时候买入并在价格为16时卖出，则能收获最大的利润11。
*/
//暴力枚举O(n^2)
class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
                if(nums[i]<nums[j])
                    res=nums[j]-nums[i]>res?nums[j]-nums[i]:res;
        }
        return res;
    }
};

//用一个变量存放前面的最小值（或者后面的最大值），可以省去一个循环
class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int res=0,minv=10000;
        for(int j=0;j<nums.size();j++){
                if(nums[j]<minv) minv=nums[j];
                    res=nums[j]-minv>res?nums[j]-minv:res;
        }
        return res;
    }
};
