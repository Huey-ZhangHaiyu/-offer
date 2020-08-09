/*给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
数据保证k大于0，且k小于等于数组长度。
样例
输入：[2, 3, 4, 2, 6, 2, 5, 1] , k=3
输出: [4, 4, 6, 6, 6, 5]
*/
/*
可以维护一个队列存储当前窗口最大值的下标
2 3 4 2 6 2 5 1
i开始遍历，先把2的下标压进去，然后指向3时，2由于小于3，会被弹出
接着指向4的时候，3会被弹出，这个时候下标已经为3可以满足一个窗口大小了，把4输出
接着指向2，没操作，把4输出，指向6，把4弹出，把6输出
*/
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        deque<int> q;//存储下标
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(q.size()&&q.front()<=i-k) q.pop_front();//踢出不在窗口范围内的数字
            while(q.size()&&nums[q.back()]<=nums[i]) q.pop_back();//踢出比当前值小的数字
            q.push_back(i);//压入当前指向值的坐标
            if(i>=k-1) res.push_back(nums[q.front()]);//当i开始满足窗口大小时，不断输出
        }
        return res;
    }
};
