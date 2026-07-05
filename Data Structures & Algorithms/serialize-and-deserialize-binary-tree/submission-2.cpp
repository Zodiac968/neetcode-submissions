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

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == nullptr) {
                res += "null,";
                continue;
            }
            res += to_string(front->val) + ",";
            if(front->left != nullptr) q.push(front->left);
            else q.push(nullptr);
            if(front->right != nullptr) q.push(front->right);
            else q.push(nullptr);
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> parents;
        TreeNode* root = nullptr;
        int lr = 0;
        int i = 0;
        string nums = "";
        while(i < data.size()){
            if(data[i] == ','){
                TreeNode* t = nullptr;
                if(nums != "null"){
                    int num = stoi(nums);
                    t = new TreeNode(num);
                }
                nums.clear();
                if(root == nullptr) root = t;
                else{
                    if(lr == 0) parents.front()->left = t;
                    else if(lr == 1) parents.front()->right = t;
                    lr++;
                    if(lr == 2 && !parents.empty()){
                        parents.pop();
                        lr = 0;
                    }
                }
                if(t != nullptr) parents.push(t);
            }
            else nums += data[i];
            i++;
        }
        return root;
    }
};
