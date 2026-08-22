/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* lns = head;
        ListNode* rns = head -> next;
        ListNode* temp = rns;
        while(rns && rns -> next){
            lns -> next = rns-> next;
            lns = lns -> next;
            rns -> next = lns -> next;
            rns = rns -> next;
        }
        lns -> next = temp;
        return head;
    }
};