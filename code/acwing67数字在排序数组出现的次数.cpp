//统计一个数字在排序数组中出现的次数。
//例如输入排序数组[1, 2, 3, 3, 3, 3, 4, 5]和数字3，由于3在这个数组中出现了4次，因此输出4。

//我的答案
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if(nums.empty()) return 0;
        int i=0,j=nums.size()-1;
        
        while(i<=j&&nums[i]!=k) i++;//i=j时可以继续，i会一直加到比j大一位
        while(i<=j&&nums[j]!=k) j--;
        
        return j-i+1;//所以k不存在时会返回0
    }
};

//用二分优化成logn
class Solution {
public:
    int getNumberOfK(vector<int>& A , int k) {
        if(!A.size()) return 0;

        int l1 = 0, r1 = A.size() - 1;
        while(l1 < r1)
        {
            int mid = l1 + r1 >> 1;
            if(A[mid] >= k) r1 = mid;
            else l1 = mid + 1;
        }


        int l2 = 0, r2 = A.size() - 1;
        while(l2 < r2)
        {
            int mid = l2 + r2 + 1 >> 1;
            if(A[mid] <= k) l2 = mid;
            else r2 = mid - 1;
        }

        if(A[l1] != k && A[l2] != k) return 0;

        return l2 - l1 + 1;
    }
};
