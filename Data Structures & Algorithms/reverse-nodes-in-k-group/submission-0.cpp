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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        int i = 0;
        ListNode *curr = head;
        ListNode *start = head;
        ListNode *prevStart = dummy;
        while(curr != nullptr){
            curr = curr->next;
            i++;
            i %= k;
            if(i == 0){ 
                ListNode *p = nullptr, *q = start, *r;
                while(q->next != curr){
                    r = q->next;
                    q->next = p;
                    p = q;
                    q = r;
                }
                q->next = p;
                prevStart->next = q;
                start->next = curr;
                prevStart = start;
                start = curr;
            }
        }
        return dummy->next;
    }
};
