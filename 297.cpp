/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode* root, stringstream &ss){
        if(root == NULL){
            ss << "*";
        }else{
            ss << "#" << root->val;
            serialize(root->left, ss);
            serialize(root->right, ss);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }
    
    TreeNode* build_tree(stringstream &ss){
        char output;
        ss >> output;
        TreeNode *root;
        if(output == '*'){
            return NULL;
        }else if(output == '#'){
            int val;
            ss >> val;
            root = new TreeNode(val);
            root->left = build_tree(ss);
            root->right = build_tree(ss);
        }
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss << data;
        TreeNode *root = build_tree(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));