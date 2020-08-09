/*
输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
例如输入12，从1到12这些整数中包含“1”的数字有1，10，11和12，其中“1”一共出现了5次。
*/

//按位计算每一个位上的1出现的次数即可
class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        if (n < 1) return 0;//错误数据
        
        int count = 0, factor = 1;
        while (n / factor != 0) {
            int cur_bit = (n / factor) % 10;
            int left = n / (factor * 10);//当前位的左右两边
            int right = n % factor;

            if (cur_bit == 0) count += left * factor;
            else if (cur_bit == 1) count += left * factor + right + 1;
            else count += (left + 1) * factor;
            
            factor *= 10;
        }
        return count;
    }
};
