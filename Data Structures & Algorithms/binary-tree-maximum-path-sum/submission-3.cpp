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
    int maxp = -1001;

    int calculateAllPaths(TreeNode* root, int curr=0){
        if(root == nullptr) return 0;
        int prev = max(root->val, root->val+curr);
        if(prev > maxp) maxp = prev;
        int l = calculateAllPaths(root->right, prev);
        int r = calculateAllPaths(root->left, prev);
        int sum = max({l+prev, r+prev, l+r+root->val});
        if(sum > maxp) maxp = sum;
        return max({l+root->val, r+root->val, root->val});
    }

    int maxPathSum(TreeNode* root) {
        calculateAllPaths(root);
        return maxp;
    }
};
