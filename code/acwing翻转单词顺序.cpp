/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。

样例
输入："I am a student."
输出："student. a am I"
*/
/*
如果不考虑单词，纯粹的全部翻转，直接双指针前后扫描就好
for(int i=0,j=s.size()-1;i<j;i++,j--) swap(s[i],s[j]);
然后再把每个单词的部分翻转就好了
这一类问题都是把问题分割成几步做，比如旋转矩阵90°，只给额外O(1)空间
先对角线翻转数字，然后上下翻转数字就好了；
*/
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            int j=i;
            while(j<s.size()&&s[j]!=' ') j++;//找到单词的一段
            reverse(s.begin()+i,s.begin()+j);//翻转
            i=j;//更新i
        }
        return s;
    }
};
