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
    int DFS(TreeNode* root, int depth){
        if(root == nullptr) return depth;
        depth++;
        int left = DFS(root->left, depth);
        int right = DFS(root->right, depth);
        if(abs(left - right) > 1) return -1;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int ans = DFS(root, 0);
        if(ans == -1) return false;
        return true;
    }
};
