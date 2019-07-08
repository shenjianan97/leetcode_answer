/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    //ans是两条路的最大    maxdeep是一条的 
    int ans;
     
    int maxdeep(TreeNode* root){
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL){
            ans = max(ans, root->val);
            return root->val;
        }else{
            int deep_left = maxdeep(root->left);
            int deep_right = maxdeep(root->right);
            int temp = max(deep_left, deep_right) + root->val;
            //此句将到叶子结点的最大改为了到任意子节点的最大
            temp = max(temp, root->val);
            ans = max(ans, temp);
            ans = max(ans, deep_left + deep_right + root->val);
            return temp;
        }
    }
    int maxPathSum(TreeNode* root) {
        ans = 0x80000000;
        int tmp = maxdeep(root);
        return ans;
    }
};