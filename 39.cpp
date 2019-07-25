class Solution {
public:
    vector<vector<int>> ans;
    
    int ans_one[100];
    
    
    void robot(vector<int>& candidates, int target, int num, int pos){
        if(target < 0)
            return;
        if(target == 0){
            vector<int> tmp;
            for(int i=0; i<num; i++){
                tmp.push_back(ans_one[i]);
            }
            ans.push_back(tmp);
        }
        for(int i=pos; i<candidates.size(); i++){
            ans_one[num] = candidates[i];
            robot(candidates, target-candidates[i], num+1, i);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        robot(candidates, target, 0, 0);
        
        return ans;
    }
};