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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int size = 1;
        int curr = 0;
        int index = 0;
        int nextCount = 0;
        if(root != nullptr) {
            q.push(root);
            res.push_back({});
        }
        while(!q.empty()){
            if(curr >= size){
                size *= 2;
                curr = nextCount;
                nextCount *= 2;
                index++;
                res.push_back({});
            }
            curr++;
            res[index].push_back(q.front()->val);
            cout << q.front()->val << " ";
            if(q.front()->left != nullptr){
                q.push(q.front()->left);
            } else nextCount++;
            if(q.front()->right != nullptr) {
                q.push(q.front()->right);
            } else nextCount++;
            q.pop();
        }
        cout << endl;
        return res;
    }
};
