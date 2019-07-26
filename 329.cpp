#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int n, m;
    
    vector<vector<int>> record;
    
    bool check(int x, int y, int dx, int dy, vector<vector<int>>& matrix){
        if(x+dx > n-1 || x+dx < 0 || y+dy > m-1 || y+dy < 0){
            return false;
        }else if(matrix[x][y] < matrix[x+dx][y+dy]){
            return true;
        }else{
            return false;
        }
    }
    
    int robot(int x, int y, vector<vector<int>>& matrix){
        if(record[x][y] != 0){
            return record[x][y];
        }
        int maxStep = 0;
        for(int dx=-1; dx<=1; dx++){
            for(int dy=-1; dy<=1; dy++){
                if(abs(dx + dy) == 1){
                    if(check(x, y, dx, dy, matrix)){
                        maxStep = max(maxStep, robot(x+dx, y+dy, matrix));
                    }else{
                        continue;
                    }
                }else{
                    continue;
                }
            }
        }
        record[x][y] = maxStep+1;
        return maxStep + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0)
            return 0;
        m = matrix[0].size();
        if(m == 0)
            return 0;
        vector<int> temp(matrix[0].size(), 0);
        record.assign(matrix.size(), temp);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, robot(i, j, matrix));
            }
        }
        return ans;
    }
};

int main(){
    vector<int> line1= {3, 4, 5};
    vector<int> line2= {3, 2, 6};
    vector<int> line3= {2, 2, 1};
    vector<vector<int>> input;
    input.push_back(line1);
    input.push_back(line2);
    input.push_back(line3);

    cout << Solution().longestIncreasingPath(input);
}