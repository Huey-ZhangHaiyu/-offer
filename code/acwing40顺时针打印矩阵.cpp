//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字

//很容易写错的错误示范
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(!matrix.size()) return res;
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};//右下左上
        int x=0,y=0,d=0;
        
        for(int k=0;k<m*n;k++){
            res.push_back(matrix[x][y]);
            mark[x][y]=true;
            
            //x+=dx[d];y+=dy[d];//继续走
            /*写成这样是不行的，因为如果x+dx已经出界，他就不能这么走
            走出界的x再进入if，换了个方向走一次，还是出界的
            if(x<0||x>=n||y<0||y>=m||mark[x][y]){//换向
                d=(d+1)%4;
                x+=dx[d];
                y+=dy[d];
            }
        }*/
        return res;
    }
};
  
//正确写法 
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(!matrix.size()) return res;
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};//右下左上
        int x=0,y=0,d=0;
        
        for(int k=0;k<m*n;k++){
            res.push_back(matrix[x][y]);
            mark[x][y]=true;
            
            int a=x+dx[d], b=y+dy[d];//继续走
            //判断继续走是否合法
            if(a<0||a>=n||b<0||b>=m||mark[a][b]){//不合法则换向
                d=(d+1)%4;
                a=x+dx[d];
                b=y+dy[d];
            }
            x=a,y=b;//换向之后的x和y
        }
        return res;
    }
};
