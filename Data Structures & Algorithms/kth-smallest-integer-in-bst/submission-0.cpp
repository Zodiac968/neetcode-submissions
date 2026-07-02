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
    void addNumbers(TreeNode* root, stack<int> &nums){
        if(root != nullptr){
            addNumbers(root->right, nums);
            nums.push(root->val);
            addNumbers(root->left, nums);
        }
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        stack<int> nums;
        addNumbers(root, nums);
        while(!nums.empty() && k > 1){
            nums.pop();
            k--;
        }
        if(nums.empty()) return -1;
        return nums.top();
    }
};
