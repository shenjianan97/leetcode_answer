#include <stdio.h>
#include <iostream>

class Solution{
    public:
        int reverse(int x){
            //x=1999999999
            long long ans = 0;
            const int maxint = 0x7fffffff;
            const int minint = 0x80000000;
            while(x!=0){
                ans = ans*10 + (x%10);
                x = x/10;
            }
            if(ans<minint || ans>maxint){
                ans = 0;
            }
            return ans;
        }
}