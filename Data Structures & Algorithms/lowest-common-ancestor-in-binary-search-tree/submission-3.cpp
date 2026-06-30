/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool findPath(TreeNode* root, TreeNode *p, vector<TreeNode*> &v){
        if(root == nullptr) {
            v.clear();
            return false;
        }
        v.push_back(root);
        if(root == p) {
            return true;
        }
        bool res;
        if(p->val < root->val) res = findPath(root->left, p, v);
        else res = findPath(root->right, p, v);
        return res;
    }

    void printPath(vector<TreeNode*> p){
        for(int i = 0; i < p.size(); i++){
            cout << p[i]->val << " -> ";
        }
        cout << endl;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp; findPath(root, p, pp);
        vector<TreeNode*> qq; findPath(root, q, qq);
        int i;
        if(pp.size() < qq.size()) i = pp.size()-1;
        else i = qq.size()-1;
        while(i >= 0){
            if(pp[i] == qq[i]) return pp[i];
            else i--;
        }
        return root;
    }
};
