//这里我们要求n!末尾有多少个0，因为我们知道0是2和5相乘得到的，而在1到n这个范围内，2的个数要远多于5的个数，所以这里只需计算从1到n这个范围内有多少个5就可以了。

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while (n) {     //count the number of factor 5;
            count+=n/5;
            n/=5;
        }
        return count;
    }
};