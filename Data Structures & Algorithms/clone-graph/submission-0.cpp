/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void connectNodes(Node* start, Node* copy, unordered_map<int, Node*>& nodes){
        for(int i = 0; i < start->neighbors.size(); i++){
            int val = start->neighbors[i]->val;
            if(nodes.find(val) == nodes.end()){
                Node* t = new Node(val);
                copy->neighbors.push_back(t);
                nodes[val] = t;
                connectNodes(start->neighbors[i], t, nodes);
            }else{
                copy->neighbors.push_back(nodes[val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* start = new Node(1);
        unordered_map<int, Node*> nodes;
        connectNodes(node, start, nodes);
        return start;
    }
};
