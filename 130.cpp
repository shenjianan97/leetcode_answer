class Solution {
public:
    int x, y;
    
    void fillO(int i, int n, vector<vector<char>>& board){
        if(i < 0 || i >= x || n < 0 || n >= y){
            return;
        }
        if(board[i][n] == 'X' || board[i][n] == '.'){
            return;
        }else if(board[i][n] == 'O'){
            board[i][n] = '.';
            fillO(i-1, n, board);
            fillO(i, n-1, board);
            fillO(i+1, n, board);
            fillO(i, n+1, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        x = board.size();
        if(x == 0)
            return;
        y = board[0].size();
        if(y == 0)
            return;
        //start from edge
        for(int i=0; i<x; i++){
            fillO(i, 0, board);
        }
        for(int i=0; i<x; i++){
            fillO(i, y-1, board);
        }
        for(int i=0; i<y; i++){
            fillO(0, i, board);
        }
        for(int i=0; i<y; i++){
            fillO(x-1, i, board);
        }
        for(int i=0; i<x; i++){
            for(int n=0; n<y; n++){
                if(board[i][n] == '.'){
                    board[i][n] = 'O';
                }
                else if(board[i][n] == 'O')
                    board[i][n] = 'X';
            }
        }
        
        return;
    }
};