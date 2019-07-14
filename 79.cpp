#include <iostream>
#include <vector>

using namespace std;

class Solution {  
public:  
    bool exist(vector<vector<char>>& board, string word) {  
        int row = board.size();  
        int col = board[0].size();  
        for (int i = 0; i < row; i++)  
        {  
            for (int j = 0; j < col; j++)  
            {  
                //visit数组记录该数组是否被访问过  
                vector<vector<bool>> visit(row, vector<bool>(col, false));  
                bool res = dfs(board, visit, i, j, word, 0);  
                if (res == true)  
                    return true;  
            }  
        }  
        return false;  
    }  
    //index表示的是当前探索的是第几个词  
    bool dfs(vector<vector<char>>& b, vector<vector<bool>>& visit, int x, int y,                //遍历数组的每一点  
        string s, int index)  
    {  
        int row = b.size();  
        int col = b[0].size();  
        if (index == s.length())  
            return true;  
        //以下几种情况 不再进行处理  
        //1、数组越界  
        //2、该节点已经访问过  
        //3、index位置的字符与字符串中的字符不符  
        else if (x < 0 || x >= row || y < 0 || y >= col   //1  
                 || visit[x][y] == true                   //2  
                 || s[index]!=b[x][y])                    //3  
            return false;  
        else  
        {  
            visit[x][y] = true;  
            //从xy出发向周围进行探索  
            bool x_1y = dfs(b, visit, x - 1, y, s, index + 1);  
            bool x1y = dfs(b, visit, x + 1, y, s, index + 1);  
            bool xy_1 = dfs(b, visit, x, y - 1, s, index + 1);  
            bool xy1 = dfs(b, visit, x, y + 1, s, index + 1);  
  
            if (x_1y || x1y || xy_1 || xy1)  
                return true;  
            else  
            {  
                visit[x][y] = false;  
                return false;  
            }  
        }  
    }  
};

int main(){
    vector<vector<char>> test;
    test.resize(1);
    test[0].push_back('a');
    test[0].push_back('p');
    test[0].push_back('p');
    test[0].push_back('l');
    test[0].push_back('e');
    string word = "appla";
    cout << Solution().exist(test, word);
}