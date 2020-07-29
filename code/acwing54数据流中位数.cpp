/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

样例
输入：1, 2, 3, 4
输出：1,1.5,2,2.5
解释：每当数据流读入一个数据，就进行一次判断并输出当前的中位数。
*/
//？？？？我对题目是不是有什么误解
class Solution {
public:
    vector<int> nums;
    int flag=0;
    void insert(int num){
        nums.push_back(num);
        sort(nums.begin(),nums.end());
        flag++;
    }

    double getMedian(){
        double res=0;
        if(flag%2==0) res=(nums[flag/2-1]+nums[flag/2])/2.0;
        if(flag%2==1) res= nums[flag/2];
        return res;
    }
};

/*
用两个堆去做，这样能保证两个堆顶就是中间相邻的两个元素
一个大根堆去存放比较小的一半数，一个小根堆存放比较大的一半数
中位数就是两个堆顶的平均或者大根堆的顶
每次读数进来大根堆，然后判断大根的顶和小根的顶的大小
如果大根顶大于小根顶，两者呼唤即可
然后再注意一下大根堆的长度
*/
//直接插大根堆，不对的话再去调整的思想很重要，因为本来就需要这么多的时间去判断，
//但是直接蒙一个的话，就有百分之50几率正确，就占到了便宜
class Solution {
public:

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    void insert(int num){
        max_heap.push(num);//直接插大根堆
        while (min_heap.size() && min_heap.top() < max_heap.top()){//大根堆的头比小根堆大，需要互换
            auto minv = min_heap.top(), maxv = max_heap.top();
            min_heap.pop(), max_heap.pop();
            max_heap.push(minv), min_heap.push(maxv);
        }
        if (max_heap.size() > min_heap.size() + 1){//如果两个堆大小不平衡
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double getMedian(){
        if (max_heap.size() + min_heap.size() & 1) return max_heap.top();
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};
