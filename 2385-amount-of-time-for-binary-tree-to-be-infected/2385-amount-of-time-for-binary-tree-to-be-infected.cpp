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
    int maxval = 0;
    int finddis(TreeNode* root ,int start){
        if(!root) return 0;
        int l = finddis(root -> left ,start);
        int r = finddis(root -> right ,start);
        if(root -> val == start){
            maxval = max(l , r);
            return -1;
        }
        if(l >= 0 && r >= 0) return max(l , r) + 1;
        maxval = max(maxval , (abs(l) + abs(r)));
        return min(l , r) - 1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        finddis(root , start);
        return maxval;
    }
};