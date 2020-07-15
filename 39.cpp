class Solution {
public:
    vector<vector<int> > results;
    vector<int> temp;
    
    void generator(int idx, vector<int>& candidates, int target){
        if(target < 0)
            return;
        if(target == 0){
            results.push_back(temp);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            generator(i, candidates, target-candidates[i]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        generator(0, candidates, target);
        
        return results;
    }
};