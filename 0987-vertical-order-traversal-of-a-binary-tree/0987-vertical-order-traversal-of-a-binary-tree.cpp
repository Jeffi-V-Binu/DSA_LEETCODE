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
    void collect (vector<vector<int>>& unsorted , TreeNode* root , int row , int col){
        if(!root) return;
        vector<int> temp = {col , row ,root -> val};
        unsorted.push_back(temp);
        collect(unsorted , root -> left , row + 1 , col - 1);
        collect(unsorted , root -> right , row + 1 , col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> unsorted;
        unsorted.reserve(1000);
        collect(unsorted , root , 0 , 0);
        sort(unsorted.begin() , unsorted.end());
        vector<vector<int>> result;
        vector<int> temp = {unsorted[0][2]};
        int prevcol = unsorted[0][0];
        int i = 1;
        int n = unsorted.size();
        while(i < n){
            if(unsorted[i][0] != prevcol){
                result.push_back(temp);
                temp = {};
                prevcol = unsorted[i][0];
            }
            temp.push_back(unsorted[i][2]);
            ++i;
        }
        result.push_back(temp);
        return result;
    }
};