/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* lcah(TreeNode* root ,TreeNode* p , TreeNode* q){
        if(!root) return NULL;
        if(root == p) return p;
        if(root == q) return q;
        TreeNode* l = lcah(root->left , p , q);
        TreeNode* r = lcah(root->right, p , q);
        if(l == NULL && r == NULL) return NULL;
        if((l == p && r == q) || ( l == q && r == p)) return root;
        if(l != NULL) return l;
        return r;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = lcah(root , p , q);
        return result;
    }
};