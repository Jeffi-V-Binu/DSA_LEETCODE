/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* l = head;
        ListNode* f = head;
        while(f != NULL && f -> next != NULL){
            l = l -> next;
            f = f -> next -> next;
            if(f == l)return true;
        }
        return false;
    }
};