//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
//{2,3,1,0,2,5,3}可以返回2或者3
/*
思路是把n[i]的数放在n[n[i]]的正确位置上，如果目标位置上已经有了正确数字，那么说明出现重复
时间复杂度是O(n)
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i<length;i++){
            if(numbers[i]<0||numbers[i]>=length) return false;
        }
        for(int i=0;i<length;i++){
            if(numbers[i]!=i){
                while(numbers[i]!=numbers[numbers[i]]) swap(numbers[i],numbers[numbers[i]]);
                if(numbers[numbers[i]]!=i){
                    duplication=&numbers[i];
                    return true;
                }
            }
            else continue;
        }
        return false;
    }
};
