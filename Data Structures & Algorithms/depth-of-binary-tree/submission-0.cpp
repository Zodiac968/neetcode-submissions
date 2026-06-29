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
    int md = 0;
    void DFS(TreeNode* root, int depth){
        if(root == nullptr) return;
        md = max(++depth, md);
        DFS(root->right, depth);
        DFS(root->left, depth);
    }
    int maxDepth(TreeNode* root) {
        DFS(root, 0);
        return md;
    }
};
