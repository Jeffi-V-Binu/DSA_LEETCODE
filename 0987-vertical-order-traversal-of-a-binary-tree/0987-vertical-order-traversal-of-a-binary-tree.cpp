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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        int minCol = 0;
        int maxCol = 0;
        unordered_map<int , vector<pair<int , int >>> interResult;
        queue<pair<TreeNode*, pair<int , int>>> que;
        que.push({root , {0 , 0 }});

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            TreeNode* node = it.first;
            int col = it.second.first;
            int row = it.second. second;

            minCol = min(minCol , col);
            maxCol = max(maxCol , col);

            interResult[col].push_back({row , node->val});

            if(node -> left){
                que.push({node -> left , {col - 1 , row + 1}});
            }
            if(node -> right){
                que.push({node -> right , {col + 1 , row + 1}});
            }
        }
        for(int i = minCol ; i <= maxCol ; ++i){
            if(interResult.find(i) == interResult.end()) continue;

            sort(interResult[i].begin() , interResult[i].end());
            vector<int> temp;
            for(auto j: interResult[i]){
                temp.push_back(j.second);
            }
            result.push_back(temp);
        }
        return result;
    }
};