/*
输入一组数字（可能包含重复数字），输出其所有的排列方式。
输入：[1,2,3]
输出：
      [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
      ]
*/
/*这道题的难点在于有重复数字，如何保证排序之后不重复？
保证原数组当中的重复数字排列之后相对位置不变即可
假设<11223>开五个坑<----->放第一个1<--1-->
第二个1只能放在第一个1后面<--1-1>这样保证不会出现正常遍历中两个1调换位置的重复情况
同理<-21-1>,<-2121>,<32121>
*/

class Solution {
public:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());//将相同的数字放在一起
        st = vector<bool>(nums.size(), false);//记录是否走过此位置
        path = vector<int>(nums.size());//挖好坑
        dfs(nums, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int u, int start){//u记录原数组的第几个数
        if (u == nums.size()){//已经找到最后一个原数组的位置
            ans.push_back(path);//记录答案
            return;
        }
        
        if(start>=nums.size()) return;//往后找不到坑，也可以不写，这次迭代什么都没做

        for (int i = start; i < nums.size(); i ++ ){//从起始点开始遍历坑
            if (!st[i]){//没走过
                path[i] = nums[u];//填上坑
                st[i] = true;//记录走过

                if (u + 1 < nums.size() && nums[u + 1] != nums[u])//下一个数不重复
                    dfs(nums, u + 1, 0);//从头开始找坑
                else//下一个数出现重复
                    dfs(nums, u + 1, i + 1);//只能从当前位置往后找坑
                st[i] = false;//回溯
            }
        }
    }
};
