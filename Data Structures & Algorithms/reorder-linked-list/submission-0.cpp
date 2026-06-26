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
        ListNode* tail = nullptr;
        ListNode* prevh = nullptr;

        while(tail != head && head->next != tail){
            tail = head;
            while(tail->next->next != nullptr) tail = tail->next;
            prevh = head;
            head = head->next;
            prevh->next = tail->next;
            tail->next->next = head;
            tail->next = nullptr;
        }
    }
};
