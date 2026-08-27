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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int cval;
        int min;
        int max;
        if(p -> val < q -> val){
            min = p -> val;
            max = q -> val;
        }else{
            min = q -> val;
            max = p -> val;
        }

        while(true){
            cval = curr -> val;
            if(min > cval) curr = curr -> right;
            else if(max < cval) curr = curr -> left;
            else break;
        }
        return curr;
    }
};