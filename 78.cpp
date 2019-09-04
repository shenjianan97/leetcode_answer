class Solution {
public:
    vector<vector<int> > output;
    
    void generate(int index, vector<int>& nums, vector<int>& tmp){
        if(index >= nums.size()){
            output.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        generate(index+1, nums, tmp);
        tmp.pop_back();
        generate(index+1, nums, tmp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        generate(0, nums, tmp);
        
        return output;
    }
};