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
    bool check(TreeNode* root, int min, int max){
        if(root == nullptr) return true;
        if(root->val >= max || root->val <= min) return false;
        if(root->left != nullptr and root->left->val >= root->val) return false;
        if(root->right != nullptr and root->right->val <= root->val) return false;
        bool res = check(root->left, min, root->val) && check(root->right, root->val, max);
        return res;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, -1001, 1001);
    }
};
