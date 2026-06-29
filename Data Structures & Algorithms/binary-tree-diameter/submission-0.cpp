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
    int path = 0;
    int DFS(TreeNode* root, int depth){
        if(root == nullptr) return depth;
        depth++;
        int left = DFS(root->left, depth);
        int right = DFS(root->right, depth);
        path = max(path, left+right-depth-depth);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root, 0);
        return path;
    }
};
