class Solution {
public:
    vector<vector<int>> ans;
    
    int ans_1[100];
    
    bool chongfu[100];
    
    void robot(int index, vector<int>& nums){
        if(index >= nums.size()){
            vector<int> tmp;
            for(int i=0; i<nums.size(); i++){
                tmp.push_back(nums[ans_1[i]]);
            }
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(chongfu[i] == false){
                ans_1[index] = i;
                chongfu[i] = true;
                robot(index+1, nums);
                chongfu[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        robot(0, nums);
        
        return ans;
    }
};