class Solution {
public:
    int is_small(int x, int y){
        long long input_x = x;
        int maxint = 0x7fffffff;
        if(input_x * input_x > maxint)
            return false;
        return x*x <= y;
    }
    
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        int left = 0, right = x;
        //若死循环，可写left = mid + 1    right = mid - 1 然后将答案写在新的变量ans里，而不是用在left
        while(left < right){
            int mid = (left + right) / 2;
            if(is_small(mid, x)){
                if(mid == left)
                    break;
                left = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }
};