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
    int maxdeep(TreeNode* root){
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }else{
            int temp = max(maxdeep(root->left), maxdeep(root->right)) + root->val;
            //此句将到叶子结点的最大改为了到任意子节点的最大
            temp = max(temp, root->val);
            return temp;
        }
    }
    int maxPathSum(TreeNode* root) {
        
    }
};