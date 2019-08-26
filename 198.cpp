class Solution {
public:
    vector<int> results;
    
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        results.assign(n+1, -1);
        
        if(n == -1){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        
        results[0] = nums[0];
        results[1] = max(nums[0], nums[1]);
        for(int index = 2; index < n+1; index++){
            results[index] = max(nums[index] + results[index-2], results[index-1]);
        }
        
        return results[n];
    }
};