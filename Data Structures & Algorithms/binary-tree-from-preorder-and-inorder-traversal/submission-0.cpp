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
    TreeNode* build(vector<int> preorder, int& i, unordered_map<int, int>& io, int l, int u){
        if(i >= preorder.size()){
            return nullptr;
        } 
        int rootIndex = io[preorder[i]];
        if(rootIndex > u || rootIndex < l){
            --i;
            return nullptr;
        } 
        TreeNode* root = new TreeNode(preorder[i]);
        TreeNode* left = build(preorder, ++i, io, l, rootIndex-1);
        TreeNode* right = build(preorder, ++i, io, rootIndex+1, u);
        root->right = right;
        root->left = left;
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        unordered_map<int, int> io;
        for(int i = 0; i < inorder.size(); i++){
            io[inorder[i]] = i;
        }
        int i = 0;
        return build(preorder, i, io, 0, inorder.size()-1);
    }
};
