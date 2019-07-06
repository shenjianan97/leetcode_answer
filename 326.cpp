#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return 0;
        //big3(3^n) % 3 == 0
        int maxint = 0x7fffffff;
        long long big3 = 1;
        while (big3 <= maxint)
        {
            big3 *= 3;
        }
        big3 /= 3;
        return !(big3 % n);
    }
};

int main(){
    cout << Solution().isPowerOfThree(28) << endl;
}