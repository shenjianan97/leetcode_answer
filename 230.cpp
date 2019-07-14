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
    int count(TreeNode *r, TreeNode * &want, int k){
        if(r==NULL) return 0;
        int c = count(r->left, want, k);
        int c2 = 0;
        if( want != NULL || k <= c){
            //只算出左边的就行了  只要want被找到就返回
            return c;
        }else{
            if(k-c == 1){
                want = r;
                return c;
            }else{
                c2 = count(r->right, want, k-c-1);
            }
        }
        return c+c2+1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *want = NULL;
        int c = count(root, want, k);
        if(want != NULL) return want->val;
        return -1;
    }
};
