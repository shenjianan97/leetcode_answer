class Solution {
public:
    vector<vector<int> > results;
    vector<int> temp;
    set<vector<int> > results_set;
    
    void generator(int idx, vector<int>& candidates, int target){
        if(target < 0)
            return;
        if(target == 0){
            results_set.insert(temp);
            return;
        }
        if(idx >= candidates.size())
            return;
        temp.push_back(candidates[idx]);
        generator(idx+1, candidates, target-candidates[idx]);
        temp.pop_back();
        generator(idx+1, candidates, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        generator(0, candidates, target);
        for(auto i=results_set.begin(); i != results_set.end(); i++){
            results.push_back(*i);
        }
        
        return results;
    }
};