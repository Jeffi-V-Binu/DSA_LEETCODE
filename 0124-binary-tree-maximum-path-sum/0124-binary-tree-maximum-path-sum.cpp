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
    int psum = INT_MIN;
    short pathfinder(TreeNode* root){
        if(!root) return INT_MIN;
        short l = pathfinder(root -> left);
        short r = pathfinder(root -> right);
        psum = max(psum ,max(root->val , max(root->val + l , max(root->val +r , root->val +r +l))));
        return max(root -> val , (root-> val + max(l , r)));
    }
    int maxPathSum(TreeNode* root) {
        pathfinder(root);
        return psum;
    }
};