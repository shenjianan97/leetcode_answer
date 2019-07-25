/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build_tree(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode *middle = new TreeNode(nums[mid]);
        middle->left = build_tree(nums, start, mid-1);
        middle->right = build_tree(nums, mid+1, end);
        
        return middle;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }else{
            return build_tree(nums, 0, nums.size()-1);
        }
    }
};