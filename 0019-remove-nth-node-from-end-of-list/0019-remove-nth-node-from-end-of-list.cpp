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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        if(head == nullptr) return head;
        ListNode* temp = head;
        while(temp != nullptr){
            ++m;
            temp = temp -> next;
        }
        if(m == 1) return nullptr;
        int target = m - n;
        temp = head;
        while(target - 1 > 0){
            temp = temp -> next;
            --target;
        }
        if(target == 0)head = head -> next ;
        else temp -> next = temp -> next -> next;
        return head;
    }
};