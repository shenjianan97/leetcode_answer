#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct TreeNode{
        int st;
        int ed;
        int h;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int s, int e, int hh){
            st = s;
            ed=e;
            h=hh;
            left=NULL;
            right=NULL;
        }
    };
    
    void insert(TreeNode *r, int st, int ed, int h){
        if(r == NULL) return;
        if(r->st > ed || r->ed < st) return;
        if(r->left == NULL && r->right == NULL){
            if(r->st >= st && ed >= r->ed){
                //不需要分裂，只需要更改值
                r->h = max(r->h, h);
            }else{
                if(r->st < st){
                    //[r->st, st-1][st, r->ed]
                    r->left = new TreeNode(r->st, st-1, r->h);
                    r->right = new TreeNode(st, r->ed, r->h);
                    insert(r->right, st, ed, h);
                    check(r);
                }else if(r->ed > ed){
                    //[r->st, ed][ed+1, r->ed]
                    r->left = new TreeNode(r->st, ed, r->h);
                    r->right = new TreeNode(ed+1, r->ed, r->h);
                    insert(r->left, st, ed, h);
                    check(r);
                }
            }
        }else{
            insert(r->left, st, ed, h);
            insert(r->right, st, ed, h);
            check(r);
        }
    }

    void check(TreeNode *r){
        //左节点 右节点都是叶子且值相等
        if(r!=NULL && r->left!=NULL && r->right!=NULL){
            if(r->left->left == NULL && r->right->left == NULL && r->left->h == r->right->h){
                r->h = r->left->h;
                free(r->left);
                free(r->right);
                r->left = NULL;
                r->right = NULL;
            }
        }
    }
    
    void buildans(TreeNode *r, vector<vector<int>>& ans, int &lasth){
        if(r==NULL) return;
        if(r->left==NULL && r->right == NULL){
            lasth=r->h;
            vector<int> aaa;
            aaa.push_back(r->st);
            aaa.push_back(r->h);
            ans.push_back(aaa);
        }else{
            buildans(r->left, ans, lasth);
            buildans(r->right, ans, lasth);
        }
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        TreeNode *root = new TreeNode(0, 0x7fffffff, 0);
        for(int i=0; i<buildings.size();i++){
            insert(root, buildings[i][0], buildings[i][1]-1, buildings[i][2]);
        }
        
        vector<vector<int>> ans;
        int lasth = 0;
        buildans(root, ans, lasth);

        
        return ans;
    }
};

int main(){
    vector<vector<int>> buildings;
    vector<int> line1 = {2, 9, 10};
    vector<int> line2 = {3, 7, 15};
    vector<int> line3 = {5, 12, 12};
    buildings.push_back(line1);
    buildings.push_back(line2);
    buildings.push_back(line3);

    vector<vector<int>> ans = Solution().getSkyline(buildings);

    return 0;
}