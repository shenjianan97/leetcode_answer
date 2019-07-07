#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int upperBound(vector<int> &nums,int leftloc,int rightloc,int val){
        while(leftloc<rightloc){
            int midloc = (leftloc + rightloc)/2;
            if(nums[midloc]<= val ) leftloc = midloc + 1 ;
            else  rightloc = midloc;
        }
        return leftloc;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int matrixlen = matrix.size();
        int leftval = matrix[0][0], rightval = matrix[matrixlen - 1][matrixlen - 1];
        //将左右value的值所对应的数都对应到k，所以最后得出的值肯定在矩阵中
        while(leftval < rightval){
            int midval = (leftval + rightval)/2;
            int cnt = 0;
            for( int i = 0 ; i< matrixlen;i++){
                cnt += Solution().upperBound(matrix[i], 0, matrixlen, midval);
            }
            if(cnt<k)   leftval = midval + 1;
            else rightval = midval;
        }
        return rightval;
    }
};

int main(){
    int nums[] = {1 ,3 ,5, 6, 9};
    vector<int> v_nums;
    v_nums.resize(5);
    for(int i=0; i < 4; i++){
        v_nums[i] = nums[i];
    }
    cout << Solution().upperBound(v_nums, 0, 4, 6) << endl;
}