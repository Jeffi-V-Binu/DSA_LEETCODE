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
    int maxh = -1;
    vector<int> result;
    void rightcheck(TreeNode* root , int h){
        if(!root) return;
        if(h > maxh){
            result.push_back(root -> val);
            ++maxh;
        }
        rightcheck(root -> right , h + 1);
        rightcheck(root -> left , h +1);
    }
    vector<int> rightSideView(TreeNode* root) {
        rightcheck(root , 0);
        return result;
    }
};