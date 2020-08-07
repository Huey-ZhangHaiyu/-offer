/*
输入一个数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，输出任意一对即可。
*/
/*
O(n)做法
从暴力做法改进而来
*/
//暴力做法
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            for(int j=0;j<i;j++)
                if(nums[i]+nums[j]==target) return vector<int> {nums[i],nums[j]};      
    }
};
//用哈希表省去一个循环
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.count(target-nums[i])) return vector<int>{target-nums[i],nums[i]};
            hash.insert(nums[i]);
        }
    }
};
