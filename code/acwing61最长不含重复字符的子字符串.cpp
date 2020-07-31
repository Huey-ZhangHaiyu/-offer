//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

/*
思路1：O(n^2)
双指针暴力枚举，i，j
对每一个i，往后扫j，把期间扫到的字符加进一个哈希表
直到扫到重复数字，记录i到j长度，完成
*/
/*
优化算法：O(2n)
因为每一次j往后走的时候，i都不可能往前走，因为上一步已经确定i到j是不重复的最大值了
所以只要每次判断j往后走一下，新的i到j之间有没有出现重复即可
如果没有重复，i不需要往后走；如果重复，那么i就往后移动到不重复
*/
class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        unordered_map<char,int> hash;//定义对应string的int值hash表
        int res=0;//result
        for(int i=0,j=0;j<s.size();j++){//j一直往后找
            hash[s[j]]++;//找到j的次数+1
            while(hash[s[j]]>1) hash[s[i++]]--;//当出现重复，i就要往后一直找，直到没有重复
            res=max(j-i+1,res);//记录此时最大距离
        }
        return res;
    }
};
