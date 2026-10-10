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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* result = new ListNode();
        ListNode* fia = result;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry){
            int sums =  carry;
            if(l1 != nullptr){
                sums += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != nullptr){
                sums += l2 -> val;
                l2 = l2 -> next;
            }
            result -> val = sums % 10;
            if(sums >= 10) carry = 1;
            else carry = 0;
            if(l1 != nullptr || l2 != nullptr || carry ){
                result -> next = new ListNode();
                result = result -> next;
            }
        }
        return fia;
    }
};