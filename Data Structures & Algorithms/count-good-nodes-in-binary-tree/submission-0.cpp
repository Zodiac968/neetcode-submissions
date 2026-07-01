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
    int compare(TreeNode* rt, int max, int count){
        if(rt == nullptr) return count;
        if(rt->val >= max) {
            count++;
            max = rt->val;
        }
        int left = compare(rt->left, max, count);
        int right = compare(rt->right, max, count);
        cout << rt->val << " " << max << " " << left << " " << right << " " << count << endl;
        return left+right-count;
    }
    
    int goodNodes(TreeNode* root) {
        return compare(root, -101, 0);
    }
};
