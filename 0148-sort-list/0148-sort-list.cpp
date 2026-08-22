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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        int leng = 0;
        ListNode* curr = head;
        while(curr){
            ++leng;
            curr = curr->next;
        }
        for(int step = 1; step < leng; step *=2){
            ListNode* prev = &dummy;
            curr = dummy.next;
            while(curr){
                ListNode* left = curr;
                ListNode* right = split(left , step);
                curr = split(right,step);
                auto [ml , lr] = merge(left , right);
                prev->next = ml;
                prev = lr;
            }
        }
        return dummy.next;
    }
    ListNode* split(ListNode* head , int step){
        if(!head) return nullptr;
        for(int i = 1 ; i < step && head->next ; ++i){
            head = head -> next;
        }
        ListNode* temp = head->next;
        head->next = nullptr;
        return temp;
    }
    pair<ListNode* , ListNode*> merge(ListNode* l1 , ListNode* l2){
        ListNode dumm(0);
        ListNode* mr = &dumm;
        while(l1 && l2){
            if(l1->val < l2-> val){
                mr -> next = l1;
                l1 = l1->next;
            }
            else{
                mr -> next = l2;
                l2 = l2 -> next;
            }
            mr = mr->next;
        }
        
        mr -> next = l1? l1: l2;
        while(mr -> next){
            mr = mr -> next;
        }
        return {dumm.next , mr};
    }
};