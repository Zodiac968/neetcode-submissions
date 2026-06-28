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
    int size;
    int capacity;

    LRUCache(int cap) {
        capacity = cap;
        size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            cout << "yes" << endl;
            Node* n = mp[key];
            if(n != tail){
                if(n == head){
                    head = head->next;
                    head->prev = nullptr;
                }else{
                    n->prev->next = n->next;
                    n->next->prev = n->prev;
                }
                tail->next = n;
                n->prev = tail;
                n->next = nullptr;
                tail = n;
            }
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* n = mp[key];
            if(n != tail){
                if(n == head){
                    head = head->next;
                    head->prev = nullptr;
                }else{
                    n->prev->next = n->next;
                    n->next->prev = n->prev;
                }
                tail->next = n;
                n->prev = tail;
                n->next = nullptr;
                tail = n;
            }
            tail->value = value;
        }
        else{
            Node *n = new Node(key, value);
            if(size < capacity){
                if(head == nullptr){
                    head = tail = n;
                }
                else{
                    tail->next = n;
                    n->prev = tail;
                    tail = n;
                }
                size++;
            }
            else if(head == tail){
                Node *d = head;
                mp.erase(d->key);
                delete d;
                d = nullptr;
                head = tail = n;
            }
            else{
                //Remove head;
                cout << head->value << endl;
                Node *d = head;
                head = head->next;
                head->prev = nullptr;
                mp.erase(d->key);
                delete d;
                d = nullptr;
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
            mp.insert({key, n});
        }
    }
};
