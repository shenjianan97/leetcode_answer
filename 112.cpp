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
    bool check(TreeNode* root, int sum, int now){
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            return (root->val + now == sum);
        }else{
            return check(root->left, sum, now + root->val) || check(root->right, sum, now + root->val);
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }else{
            return check(root, sum, 0);
        }
    }
};