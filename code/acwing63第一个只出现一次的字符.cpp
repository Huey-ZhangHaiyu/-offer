/*
在字符串中找出第一个只出现一次的字符。
如输入"abaccdeff"，则输出b。

如果字符串中不存在只出现一次的字符，返回#字符。
*/

//思路有，但是写不对！
class Solution {
public:
    char firstNotRepeatingChar(string s) {
        int n=s.size();
        for(int i=0;i<n;i++) {
            if(s[i]!='*') {
                for(int j=i+1;j<n;j++)
                    if(s[j]==s[i]) s[j]='*',s[i]='*';
                }
            }
            else continue;
        }
        for(int i=0;i<n;i++){
            if(s[i]!='*') return s[i];
        }
        return '#';
    }
};

//大佬写的，学到了
class Solution {
public:
    char firstNotRepeatingChar(string s) {
        unordered_map<char, int> hash;
        char res='#';
        for(auto x:s) hash[x]++;
        for(auto x:s) 
            if(hash[x]==1){
                res=x;
                break;
            }
        return res;
    }
};
