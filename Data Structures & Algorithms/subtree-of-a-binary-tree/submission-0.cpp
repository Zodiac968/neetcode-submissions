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
    bool checkSubRoot(TreeNode* rt, TreeNode* st){
        if(st == nullptr && rt == nullptr) return true;
        else if(rt == nullptr) return false;
        else if(st == nullptr) return false;

        if(rt->val == st->val){
            return checkSubRoot(rt->left, st->left) && checkSubRoot(rt->right, st->right);
        }
        else{
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        else if(root == nullptr) return false;
        cout << root->val << endl;
        if(!checkSubRoot(root, subRoot)) 
            return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
        else return true;
    }
};
