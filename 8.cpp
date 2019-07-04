#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        int is_positive = 1;
        int maxint = 0x7fffffff;
        int minint = 0x80000000;
        long long max = 0x100000000;
        if(str.length() == 0)
            return 0;
        //reduce space
        int pos = 0;
        while(str[pos] == ' '){
            pos++;
        }
        if((str[pos] < '0' || str[pos] > '9') && str[pos] != '+' && str[pos] != '-'){
            return 0;
        }
        //judge sign
        if(str[pos] == '+'){
            is_positive = 1;
            pos++;
        }else if(str[pos] == '-'){   
            is_positive = 0;
            pos++;
        }
        for(int i=pos; i < str.length(); i++){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            ans = ans*10 + str[i] - '0';
            if(ans >= max){
                if(is_positive == 1){
                    return maxint;
                }else{
                    return minint;
                }
            }
        }
        if(is_positive == 0){
            ans = -ans;
        }
        if(ans > maxint) ans = maxint;
        if(ans < minint) ans = minint;
        return ans;
    }
};

int main(){
    int ans =  Solution().myAtoi("2147483648");
    cout << ans << endl;
}