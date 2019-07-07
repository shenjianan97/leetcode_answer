class Solution {
public:
    int guess(long mid, vector<int>& nums, long m){
        long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > mid){
                m--;
                sum = nums[i];
                if(nums[i] > mid){
                    return false;
                }
            }else{
                sum += nums[i];
            }
        }
        return m >= 1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long n = nums.size();
        long long R = 1;
        for(int i = 0; i < n; i++){
            R += nums[i];
        }
        long long L = 0;
        long long ans = 0;
        
        while(L < R){
            long long mid = (L + R) / 2;
            if(guess(mid, nums, m)){
                ans = mid;
                //L = mid + 1;
                R = mid;
            }else{
                L = mid + 1;
                //R = mid;
            }
        }
        return (int)ans;
    }
};