/*
在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。
请找出那个只出现一次的数字。
你可以假设满足条件的数字一定存在。

要求只使用 O(n) 的时间和额外 O(1) 的空间（所以不能用哈希）
*/

/*
因为除了一个数只出现一次，其他数都出现了3次，那么二进制中每一位1的个数%3不等于0
说明这个数在这一位为0，否则为1，这样的到每一位的值就行了
int是32位，
*/
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i <32; i++) {
            int cnt = 0;
            for (int x: nums) 
                if (x >> i & 1) cnt ++;

            if (cnt % 3) ans +=pow(2,i);//这里卡了一晚上因为次方不能用^！！！！！
        }
        return ans;
    }
};
/*
牛逼的算法：利用位运算32位其实只是O(1)
状态机：设计一个遇到1转移状态，每3次一个循环，遇到0自环的状态机
(ones,twos) 
ones=(ones^x)&~twos
twos=(twos^x)&~ones;
遇到1：(0,0)->(1,0)->(0,1)->(0,0)
遇到0：(0,0)->(0,0)；(0,1)->(0,1)；(1,0)->(1,0)；
*/
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int ones=0,twos=0;
        for(auto x:nums){
            ones=(ones^x)&~twos;
            twos=(twos^x)&~ones;
        }
        return ones;
    }
};
