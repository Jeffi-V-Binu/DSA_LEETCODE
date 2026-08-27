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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        while(curr){
            if(!curr -> left){
                result.push_back(curr->val);
                curr = curr -> right;
            }
            else{
                TreeNode* prec = curr -> left;
                while(prec-> right != nullptr && prec -> right != curr){
                    prec = prec -> right;
                }
                if(prec -> right != curr){
                    prec -> right = curr;
                    curr = curr -> left;
                }
                else{
                    result.push_back(curr->val);
                    prec -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return result;
    }
};