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
    unordered_map<int , int> inolookup;
    TreeNode* assignroot(vector<int>& preorder ,int ins , int ine){
        if(ins > ine) return NULL;
        int rootval = preorder[pos++];
        TreeNode* root = new TreeNode(rootval);
        int rind = inolookup[rootval];
        root -> left = assignroot(preorder , ins , rind - 1);
        root -> right = assignroot(preorder , rind + 1 , ine);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos = 0;
        inolookup.clear();

        int n = inorder.size();
        for(int i = 0 ; i < n ; ++i){
            inolookup[inorder[i]] = i;
        }

        return assignroot(preorder , 0 , n - 1);
    }
};