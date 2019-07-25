class Solution {
public:
    vector<vector<int>> ans;
    
    int path[1000];
    
    void robot(int index, int k, int n){
        if(n < 0)
            return;
        if(index > k)
            return;
        if(n == 0 && index == k){
            vector<int> tmp;
            for(int i=0; i<k; i++){
                tmp.push_back(path[i]);
            }
            ans.push_back(tmp);
            
            return;
        }
        for(int i=path[index-1]+1; i<10; i++){
            path[index] = i;
            robot(index+1, k, n-i);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        robot(0, k, n);
        
        return ans;
    }
};