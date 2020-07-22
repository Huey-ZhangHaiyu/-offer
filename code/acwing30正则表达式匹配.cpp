//请实现一个函数用来匹配包括'.'和'*'的正则表达式。
//模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
//在本题中，匹配是指字符串的所有字符匹配整个模式。
//例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。
/*
想法动态规划
状态表示：f[i][j]表示p从j开始到结尾，是否能匹配s从i开始到结尾
状态转移：三种情况
1.如果p[j+1]不是通配符'*'，则f[i][j]是真，当且仅当s[i]可以和p[j]匹配，且f[i+1][j+1]是真；
如果p[j+1]是通配符'*'，则下面的情况只要有一种满足，f[i][j]就是真；
2.f[i][j+2]是真；也就是*取0
3.s[i]可以和p[j]匹配，且f[i+1][j]是真；也就是s[i]和p[j]相等，且s[i]之后的一段数能被*代替
*/
class Solution {
public:
    vector<vector<int>>f;//储存状态
    int n, m;
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));//初始化为全-1
        return dp(0, 0, s, p);
    }

    bool dp(int x, int y, string &s, string &p)
    {
        if (f[x][y] != -1) return f[x][y];//搜寻过了
        if (y == m)//搜寻到了最后，则正确
            return f[x][y] = x == n;
        bool first_match = x < n && (s[x] == p[y] || p[y] == '.');//对应匹配的条件
        bool ans;
        if (y + 1 < m && p[y + 1] == '*')//p[y+1]='*'，两种情况
        {
            ans = dp(x, y + 2, s, p) || first_match && dp(x + 1, y, s, p);
        }
        else
            ans = first_match && dp(x + 1, y + 1, s, p);//如果不是*，则看是否直接匹配
        return f[x][y] = ans;
    }
};
