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

//维护优先队列
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        //priority_queue<int,vector<int>,greater<int>> small_heap;
        priority_queue<int> heap;//priority_queue默认vector，默认大顶堆
        for(auto x : input){
            heap.push(x);
            if(heap.size() > k) heap.pop(); 
        }
        while(heap.size()){
            res.push_back(heap.top());
            heap.pop();
        }
        reverse(res.begin(),res.end());//从小到大排列
        return res;
    }
};

//快排
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        for(int i = 1;i <= k;i++)
            res.push_back(quick_select(input,0,input.size()-1,i));
        return res;
    }

    int quick_select(vector<int>& q,int l,int r,int k){
        if(l >= r) return q[l];
        int i = l-1,j = r+1,x = q[l+r >> 1];
        while(i < j){
            do i++;while(q[i] < x);
            do j--;while(q[j] > x);
            if(i < j) swap(q[i],q[j]);
        }
        if(k <= j-l+1) return quick_select(q,l,j,k);
        else return quick_select(q,j+1,r,k-(j-l+1));
    }
};
