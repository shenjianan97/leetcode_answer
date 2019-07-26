class Solution {
public:
    int x, y;
    
    void killIsland(int i, int n, vector<vector<char>>& grid){
        if(i < 0 || i >= x || n < 0 || n >= y){
            return;
        }
        if(grid[i][n] == '0'){
            return;
        }else{
            grid[i][n] = '0';
            killIsland(i-1, n, grid);
            killIsland(i, n-1, grid);
            killIsland(i+1, n, grid);
            killIsland(i, n+1, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        x = grid.size();
        if(x == 0)
            return 0;
        y = grid[0].size();
        if(y == 0)
            return 0;
        int count = 0;
        for(int i=0; i<x; i++){
            for(int n=0; n<y; n++){
                if(grid[i][n] == '1'){
                    count++;
                    killIsland(i, n, grid);
                }
            }
        }
        
        return count;
    }
};