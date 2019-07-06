#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int result = n;
        set<int> temp;
        while(1){
            if(result == 1)
                return true;
            if(temp.count(result) == 1)
                return false;
            temp.insert(result);
            result = get_result(result);
            cout << "result: " << result << endl;
        }
    }
    
    int get_result(int n){
        int output = 0;
        while(n != 0){
            int digit = n % 10;
            output += digit * digit;
            n /= 10;
        }
        return output;
    }
};

int main(){
    Solution().isHappy(2);
}