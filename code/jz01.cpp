//find number in 2-dimentional array
//在一个二维数组中（每个一维数组的长度相同）
//每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
/*
有点类似于二分，因为左下角和右上角会导致两个单调
左下角的右边单调递增，上面一列单调递减，所以可以用左下角作为分割条件，一行一行排除
右上角同理
*/
//c++11
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty()||array[0].empty()) return false;//要先判断这个，因为如果是空数组
        int x=array[0].size(),y=array.size();//array[0]就不存在，所以x会报错
        int i=0; int j=y-1;
        while(i<x&&j>=0){
            if(array[i][j]==target) return true;
            if(array[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};

//c++98
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=array.size();
        int col=array[0].size();
        int i=row-1;
        int j=0;
        for(i,j;i>=0&&j<col;){
            if(target==array[i][j]){return true;}
            if(target>array[i][j]){
                j++;
                continue;
            }
            else if(target<array[i][j]){
                i--;
                continue;
            }
        }
        return false;
    }
};
