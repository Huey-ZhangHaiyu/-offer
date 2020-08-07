/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
你可以假设这两个数字一定存在。
*/
//O(2n)
class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> ans;
        for(auto x:nums)
            hash[x]++;
        for(auto x:nums)
            if(hash[x]==1) ans.push_back(x);
        return ans;
    }
};

/*
考虑一下只有一个数重复，12233445566
由于异或运算具有交换律，相同为0，最后剩下的一定是只出现一次的数：1^2^2^3^3^4^4^5^5^6^6=1
就完了
两个数重复的话，异或到最后剩下的是a^b，那么二进制中，1的地方说明a和b那一位不同，0的地方相同
随便找一个异或结果为1的位，将原来的数分成那一位为0和1的两个集合，那么这两个数一定分别在两个集合里
就变成了两个只出现一次的数的问题了
*/
class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        int s=0,k=0,a=0,b=0;
        for(auto x:nums) s^=x;//得到s=a^b
        while(!(s&1<<k)) k++;//第k位为1//这里的！后面记得加括号！！！比&优先
        for(auto x:nums)
            if(x&(1<<k))
                a^=x;
            //else b^=x;
        return vector<int>{a,s^a};
    }
};
