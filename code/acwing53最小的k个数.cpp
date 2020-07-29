/*
输入n个整数，找出其中最小的k个数。

注意：
数据保证k一定小于等于输入数组的长度;
输出数组内元素请按从小到大顺序排序;
*/

//？？好像有哪里不太对？
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
    }
};
