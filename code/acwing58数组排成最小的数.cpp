/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组[3, 32, 321]，则打印出这3个数字能排成的最小数字321323。

样例
输入：[3, 32, 321]
输出：321323
*/

/*排列具有传递性！
if ab>ba,bc>cb
then ac>ca, abc is the minimum
所以自定义数组排序方式，按照上面的比较方法，从小到大排序即是结果
*/

class Solution {
public:
    static bool my_cmp(int a, int b){
        auto sa=to_string(a), sb=to_string(b);
        return sa+sb<sb+sa;
    }
    
    string printMinNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),my_cmp);
        string res;
        for(auto x:nums){
            res+=to_string(x);
        }
        return res;
    }
};
