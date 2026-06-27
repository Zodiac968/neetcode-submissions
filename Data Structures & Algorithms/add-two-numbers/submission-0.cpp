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
        ListNode* head;
        ListNode *greater = l1, *lesser = l2;
        while(greater->next != nullptr && lesser->next != nullptr){
            greater = greater->next;
            lesser = lesser->next;
        }
        if(greater->next == nullptr){
            greater = l2;
            lesser = l1;
        }
        else {
            greater = l1;
            lesser = l2;
        }

        int carry = 0;
        ListNode *prev = nullptr;
        ListNode *curr = nullptr;
        while(lesser != nullptr){
            int sum = greater->val + lesser->val + carry;
            carry = sum/10;
            sum %= 10;
            if(curr == nullptr){
                curr = new ListNode(sum);
                head = curr;
            }
            else curr = new ListNode(sum);

            if(prev != nullptr) prev->next = curr;
            cout << curr->val << endl;
            prev = curr;
            greater = greater->next;
            lesser = lesser->next;
        }
        while(greater != nullptr){
            int sum = greater->val + carry;
            carry = sum/10;
            sum %= 10;
            curr = new ListNode(sum);
            prev->next = curr;
            cout << curr->val << endl;
            prev = curr;
            greater = greater->next;
        }
        if(carry != 0){
            cout << carry << endl;
            curr = new ListNode(carry);
            prev->next = curr;
            prev = curr;
        }
        return head;
    }
};
