//第一反应是用队列做，但是复杂度比较高
class Solution {
public:
    string leftRotateString(string str, int n) {
        queue<char> q;
        for(auto x:str) q.push(x);
        for(int i=0;i<n;i++){
            char temp=q.front();
            q.pop();
            q.push(temp);
        }
        for(int i=0;i<q.size();i++){
            str[i]=q.front();
            q.pop();
        }
        return str;
    }
};

//还是和上一题一样，分几步走
class Solution {
public:
    string leftRotateString(string str, int n) {
        reverse(str.begin(),str.end());
        reverse(str.begin(),str.end()-n);
        reverse(str.end()-n,str.end());//stl的算法基本都是[begin, end)
        return str;
    }
};
