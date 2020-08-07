
/*
因为是正整数序列
假设i+…+j=s
那么如果i往后移动，要保证i'+……+j'=s，j'一定比j大
如果j不动，那么新区间就会被原区间包含，加起来一定小于s
*/
class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> res;
        for(int i=1, j=1, s=1;i<(sum+1)/2;i++){//i为sum/2时，i+j一定已经大于sum
            while(s<sum) s+=++j;//计算当前总和
            if(s==sum&&j-i>0){//如果找到答案，序列至少2个数
                vector<int> v;
                for(int k=i;k<=j;k++){
                    v.push_back(k);
                }
                res.push_back(v);
            }
            s-=i;//i会往后移，s要减去当前i
        }
        return res;
    }
};
