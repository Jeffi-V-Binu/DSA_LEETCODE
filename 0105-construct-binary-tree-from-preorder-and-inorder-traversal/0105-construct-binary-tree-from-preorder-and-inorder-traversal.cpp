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
private:
    int pos = 0;
    int ind = 0;
    TreeNode* assignroot(vector<int>& preorder ,vector<int>& inorder , int stop){
        if(pos >= preorder.size() || inorder[ind] == stop) return NULL;
        TreeNode* root = new TreeNode(preorder[pos++]);
        root -> left = assignroot(preorder , inorder, root -> val);
        ++ind;
        root -> right = assignroot(preorder , inorder, stop);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos = 0;
        ind = 0;
        return assignroot(preorder , inorder , INT_MIN);
    }
};