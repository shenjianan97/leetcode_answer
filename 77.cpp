//默认结果从小到大

class Solution {
public:
    vector<vector<int>> ans;
    
    int path[100];
    
    int path_length = 0;
    
    void robot(int index, int n, int k){ //index [0, n] 最后一位搜索的数值
        if(k == 0){
            vector<int> tmp;
            for(int i=0; i<path_length; i++){
                tmp.push_back(path[i]);
            }
            ans.push_back(tmp);
            return;
        }
        for(int i=index+1; i<=n; i++){
            path[path_length - k] = i;
            robot(i, n, k-1);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        path_length = k;
        robot(0, n, k);
        
        return ans;
    }
};