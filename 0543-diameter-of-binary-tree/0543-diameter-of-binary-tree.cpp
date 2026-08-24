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
    int dia = 0;
    short heigh(TreeNode* root){
        if(!root){
            return 0;
        }
        short l = heigh(root -> left);
        short r = heigh(root -> right);
        dia = max(dia , (l+r));
        return 1 + max(l , r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heigh(root);
        return dia;
    }
};