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
    void reorderList(ListNode* head) {
        ListNode* tail = head, *l1 = head, *l2 = head;
        int midpoint = 0;
        while(tail->next != nullptr){
            tail = tail->next;
            midpoint++;
        }
        midpoint /= 2;
        if(midpoint == 0) return;
        while(midpoint >= 0){
            if(midpoint == 0){
                ListNode* temp = l2;
                l2 = l2->next;
                temp->next = nullptr;
            }
            else l2 = l2->next;
            midpoint--;
        }
        ListNode* p = nullptr, *q = l2, *r;
        while(q->next != nullptr){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        q->next = p;
        l2 = q;
        while(l1 != nullptr){
            ListNode* t1 = l1->next;
            if(t1 == nullptr){
                l1->next = l2;
                break;
            }
            ListNode* t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }
    }
};
