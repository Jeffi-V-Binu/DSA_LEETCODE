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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while(curr-> val != key){
            prev = curr;
            if(curr -> val < key){
                curr = curr -> right;
                if(curr == nullptr) return root;
            }
            else{
                curr = curr -> left;
                if(curr == nullptr) return root;
            }
        }
        if(curr -> left == nullptr || curr -> right == nullptr){
            TreeNode* child = curr -> left ? curr -> left : curr -> right;
            if(!prev){
                delete curr;
                return child;
            }
            if(prev -> left == curr)prev -> left = child;
            else prev -> right = child;
            delete curr;
            return root;
        }
        TreeNode* pdpre = curr;
        TreeNode* pred;
        pred = curr -> right;
        while(pred -> left){
            pdpre = pred;
            pred = pred -> left;
        }
        if(pdpre -> left == pred) pdpre -> left = pred -> right;
        else pdpre -> right = pred -> right;
        curr -> val = pred -> val ;
        delete pred;
        return root;
    }
};