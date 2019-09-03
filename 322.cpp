#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > save;
    int maxValue = 100000;
    
    // int solve(int index, int am, vector<int>& coins){
    //     if(am < 0){
    //         return maxValue;
    //     }
    //     if(am == 0){
    //         return 0;
    //     }
    //     if(index >= coins.size()){
    //         return maxValue;
    //     }
    //     if(save[index][am] > -10){
    //         return save[index][am];
    //     }
        
    //     int answer = min(solve(index, am-coins[index], coins) + 1, solve(index+1, am, coins));
        
    //     save[index][am] = answer;
    //     return answer;
    // }

    int solve(int index, int am, vector<int>& coins){
        for(int i=0; i<coins.size(); i++){
            save[i][0] = 0;
            for(int n=i; n<coins.size(); n++){
                save[i][coins[n]] = 1;
            }
        }
        for (int index = 0; index < coins.size()-1; index++)
        {
            for(int amount = 0; amount <= am; amount++){
                    if(amount+coins[index] <= am){
                        if(index+1 > coins.size()){
                            save[index][amount+coins[index]] = min(save[index][amount]+1, maxValue);
                        }else{
                            save[index][amount+coins[index]] = min(save[index][amount]+1, save[index+1][amount + coins[index]]);
                        }
                    }
            }
        }
        
        return save[0][am];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> line(amount+1, maxValue);
        save.assign(coins.size(), line);
        int output = solve(0, amount, coins);
        if(output > maxValue){
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