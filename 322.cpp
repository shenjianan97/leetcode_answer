#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue = 100000;

    vector<vector<int> > save;
    
    //第二个参数是进入index之前的剩余钱数
    int solve(int index, int am, vector<int>& coins){
        if(am < 0){
            return maxValue;
        }
        if(am == 0){
            return 0;
        }
        if(save[index][am] > -10){
            return save[index][am];
        }

        int min = 0x7fffffff;
        for(int i=0; i<coins.size(); i++){
            int a = solve(i, am-coins[i], coins) + 1;
            if(min > a){
                min = a;
            }
        }
        save[index][am] = min;

        return save[index][am];
    }

    int solve_outer(int am, vector<int>& coins){
        int min = 0x7fffffff;
        for(int i=0; i<coins.size(); i++){
            int a = solve(i, am-coins[i], coins) + 1;
            if(a < min){
                min = a;
            }
        }

        return min;
    }
    
    int coinChange(vector<int>& coins, int am) {
        vector<int> line(amount+1, -10);
        save.assign(coins.size(), line);

        int answer = solve_outer(amount, coins);
        if(answer >= maxValue){
            return -1;
        }else{
            return answer;
        }

        for(int i=0; i<coins.size(); i++){
            for(int amount=0; amount<=am; amount++){
                int min_value = 0x7fffffff;
                if(amount-coins[i] >= 0){
                    min_value = min(save[i][amount-coins[i]] + 1, min_value);
                }
                save[amount] = save[amount-coins[i]] + 1;
            }
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