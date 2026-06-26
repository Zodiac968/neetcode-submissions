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
        ListNode* tail = head, *prev = nullptr;
        int len = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }
        len -= n;
        tail = head;
        while(len > 0){
            prev = tail;
            tail = tail->next;
            len--;
        }
        if(prev != nullptr)
            prev->next = tail->next;
        else
            head = tail->next;
        return head;
    }
};
