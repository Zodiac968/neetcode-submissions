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
    void print(ListNode* h){
        ListNode* curr = h;
        while(curr != nullptr){
            cout << curr->val << " , ";
            curr = curr->next;
        }
        cout << endl;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1001);
        for(int i = 0; i < lists.size(); i++){
            ListNode* currO = head;
            ListNode* prevO = nullptr;
            ListNode* currL = lists[i];
            while(currL != nullptr && currO != nullptr){
                if(currO->val > currL->val){
                    ListNode *temp = currL->next;
                    prevO->next = currL;
                    prevO = prevO->next;
                    currL->next = currO;
                    currL = temp;
                }else{
                    prevO = currO;
                    currO = currO->next;
                }
            }
            if(currL != nullptr){
                prevO->next = currL;
            }
        }
        return head->next;
    }
};
