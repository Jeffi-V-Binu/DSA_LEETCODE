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
    void assignroot(TreeNode* root ,vector<int>& preorder , vector<int>& inorder , int ins , int ine , int& pos){
        root -> val = preorder[pos];
        int i;
        for(i = ins ; i <= ine ; ++i){
            if(inorder[i] == preorder[pos])break;
        }
        TreeNode* l = new TreeNode();
        TreeNode* r = new TreeNode();
        if(i > ins){
            assignroot(l , preorder , inorder , ins , i - 1 , ++pos);
            root-> left = l;
        }
        if(i < ine){
            assignroot(r , preorder , inorder , i + 1 , ine , ++pos);
            root -> right = r;
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        TreeNode * dummy = new TreeNode();
        pos = 0;
        assignroot(dummy , preorder , inorder , 0 , n - 1 , pos);
        return dummy;
    }
};