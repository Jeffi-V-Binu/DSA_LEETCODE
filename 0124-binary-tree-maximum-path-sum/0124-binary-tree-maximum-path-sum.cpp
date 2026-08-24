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
    int pathfinder(TreeNode* root){
        if(!root) return 0;
        int l = max(0, pathfinder(root -> left));
        int r = max(0, pathfinder(root -> right));
        psum = max(psum ,root->val +r +l);
        return root-> val + max(l , r);
    }
    int maxPathSum(TreeNode* root) {
        pathfinder(root);
        return psum;
    }
};