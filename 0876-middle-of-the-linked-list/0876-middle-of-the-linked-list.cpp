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
    void maxl(ListNode* pt , int& count){
        if(pt -> next != nullptr){
            ++count;
            maxl(pt->next , count);
        }
        else{
            ++count;
        }
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        maxl(temp , count);
        int midl = (count/2);
        while(midl > 0){
            temp = temp -> next;
            --midl;
        }
        return temp;
    }
};