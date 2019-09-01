#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > save;
    
    int solve(int index, int am, vector<int>& coins){
        if(am < 0){
            return 1000000;
        }
        if(am == 0){
            return 0;
        }
        if(save[index][am] > -10){
            return save[index][am];
        }
        int min = 10000000;
        for(int i=0; i<coins.size(); i++){
            int a = solve(i, am-coins[i], coins) + 1;
            if(min > a){
                min = a;
            }
        }
        
        save[index][am] = min;
        return min;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> line(amount+1, -10);
        save.assign(coins.size(), line);
        int output = solve(0, amount, coins);
        if(output > 1000000){
            return -1;
        }else{
            return output;
        }
    }
};

int main(){
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    int amount = 5;
    cout << Solution().coinChange(input, amount) << endl;
}