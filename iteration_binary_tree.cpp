#include <iostream>
#include <stack>

using namespace std;

typedef struct TreeNode{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
}TreeNode;

typedef struct StackNode{
    TreeNode * r;
    int state;
}StackNode;

void InOrder3(TreeNode *r){
    StackNode snode;
    snode.r = r;
    stack<StackNode> s;
    while(snode.r != NULL || !s.empty()){
        while (!s.empty() && (snode.r == NULL || snode.state >= 3))
        {
            snode = s.top();
            s.pop();
            snode.state++;
        }
        if(snode.r == NULL || snode.state >= 3){
            break;
        }
        switch (snode.state)
        {
            case 0:
                s.push(snode);
                snode.r = snode.r->left;
                break;
            case 1:
                cout << snode.r->val << " ";
                snode.state++;
                break;
            case 2:
                s.push(snode);
                snode.r = snode.r->right;
                snode.state = 0;
                break;
            default:
                break;
        }
    }
}