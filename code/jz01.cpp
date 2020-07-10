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
