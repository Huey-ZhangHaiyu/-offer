//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

//输入一个升序的数组的一个旋转，输出旋转数组的最小元素。

//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

//数组可能包含重复项。

//注意：数组内所含元素非负，若数组大小为0，请返回-1。

//第一个小于array[0]的就是答案喽
class Solution {
public:
    int minNumberInRotateArray(vector<int> nums) {
        int n=nums.size();
        if(!n) return -1;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[0]) return nums[i];
            return nums[0];//找不到的话就可能单增[1,2,3,4,5,6,7,8,9,1,1]
        }
    }
};

//把尾部重复的数字去掉就可以用二分法
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 0) return -1;
        while (n > 0 && nums[n] == nums[0]) n -- ;//删除屁股上的重复元素
        if (nums[n] >= nums[0]) return nums[0];//存在删除后单调递增的情况，如果数组是[1,2,3,4,5,6,7,8,9,1,1]
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;       // [l, mid], [mid + 1, r]
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};
