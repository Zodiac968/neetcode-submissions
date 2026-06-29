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
    bool compareTree(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr) return false;
        else if(q == nullptr) return false;
        bool res = compareTree(p->right, q->right) && compareTree(p->left, q->left);
        if(res && p->val == q->val) return true;
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compareTree(p, q);
    }
};
