/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        vector<Node*> nodes;
        unordered_map<Node*, int> indexMap;
        Node* curr = head, *prev = nullptr;
        int i = 0;
        while(curr != nullptr){
            Node *n = new Node(curr->val);
            indexMap.insert({curr, i});
            if(prev != nullptr) prev->next = n;
            nodes.push_back(n);
            prev = n;
            curr = curr->next;
            i++;
        }
        curr = head;
        i = 0;
        while(curr != nullptr){
            if(curr->random == nullptr) nodes[i]->random = nullptr;
            else nodes[i]->random = nodes[indexMap[curr->random]];
            curr = curr->next;
            i++;
        }
        return nodes[0];
    }
};
