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
    unordered_map<int , vector<int>> adjlist;
    void converttogf(TreeNode* root , TreeNode* parent){
        if(!root) return;
        if(parent){
            adjlist[root-> val].push_back(parent->val);
            adjlist[parent -> val].push_back(root->val);
        }
        converttogf(root->left , root);
        converttogf(root->right , root);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        queue<int> Q;
        converttogf(root , NULL);
        unordered_set<int> check;
        Q.push(start);
        check.insert(start);
        int minutes = -1;
        while(!Q.empty()){
            int n = Q.size();
            ++minutes;
            for(int i = 0 ; i < n ; ++i){
                int temp = Q.front();
                Q.pop();
                for(int c : adjlist[temp]){
                    if(check.find(c) == check.end()){
                        Q.push(c);
                        check.insert(c);
                    }
                }
            }
        }
        return minutes;
    }
};