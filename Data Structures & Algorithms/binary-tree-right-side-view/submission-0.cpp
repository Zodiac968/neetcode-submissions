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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        int size = 1;
        int s = 0;
        int nextCount = 0;
        if(root != nullptr) q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            cout << curr->val << " ";
            s++;
            if(curr->left != nullptr) q.push(curr->left);
            else nextCount++;
            if(curr->right != nullptr) q.push(curr->right);
            else nextCount++;
            q.pop();
            if(s >= size){
                cout << endl;
                res.push_back(curr->val);
                size *= 2;
                s = nextCount;
                nextCount *= 2;
            }
        }
        return res;
    }
};
