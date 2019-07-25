#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//难点在于去重

class Solution {
public:
    vector<vector<int>> ans;
    
    bool v[100];
    
    //相同连续元素只有连续的取前面的合法
    void robot(vector<int>& nums, int index){
        if(index >= nums.size()){
            vector<int> tmp;
            for(int i=0; i<nums.size(); i++){
                if(v[i]){
                    tmp.push_back(nums[i]);
                }
            }
            ans.push_back(tmp);
            return;
        }
        if(index > 0 && nums[index - 1] == nums[index] && v[index-1] == false){
            v[index] = false;
            robot(nums, index+1);
        }else{
            v[index] = true;
            robot(nums, index+1);
            
            v[index] = false;
            robot(nums, index+1);
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        robot(nums, 0);
        
        return ans;
    }
};