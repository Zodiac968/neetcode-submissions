class LRUCache {
public:
    struct Node {
        int key; 
        int value;
        Node* next;
        Node* prev;

        Node(int k, int val){
            key = k;
            value = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, Node*> mp;
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    int capacity;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-2, -1);
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }

    void remove(Node* n){
        n->next->prev = n->prev;
        n->prev->next = n->next;
        n->next = n->prev = nullptr;
    }

    void append(Node* n){
        tail->prev->next = n;
        n->prev = tail->prev;
        n->next = tail;
        tail->prev = n;
    }

    void printLinkedList(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->value << " , ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* n = mp[key];
            remove(n);
            append(n);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* n = mp[key];
            remove(n);
            append(n);
            n->value = value;
        }
        else{
            Node *n = new Node(key, value);
            if(size >= capacity){
                cout << size << " " << capacity << endl;
                Node *d = head->next;
                remove(d);
                mp.erase(d->key);
                delete d;
                d = nullptr;
            }
            append(n);
            mp.insert({key, n});
            size++;
        }
    }
};
