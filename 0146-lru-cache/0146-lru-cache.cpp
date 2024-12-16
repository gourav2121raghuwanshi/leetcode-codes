class LRUCache {
    class Node {
    public:
        int key;
        int data;
        Node* prev;
        Node* next;
        Node(int d, int dd) {
            key = d;
            data = dd;
            prev = nullptr;
            next = nullptr;
        }
    };
    int size;
    int curr;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

public:
    LRUCache(int capacity) {
        size = capacity;
        curr = 0;
        head->next = tail;
        tail->prev = head;
    }

    unordered_map<int, Node*> mp;

    int get(int key) {
        if (mp.count(key)) {
            Node* its = mp[key];
            Node* prev = its->prev;
            Node* next = its->next;
            prev->next = next;
            next->prev = prev;
           
            head->next->prev = its;
            its->next = head->next;
            its->prev = head;
            head->next = its;
            
            return its->data;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* its = mp[key];
            Node* prev = its->prev;
            Node* next = its->next;
            prev->next = next;
            next->prev = prev;
            Node* temp = new Node(key, value);
            head->next->prev = temp;
            temp->next = head->next;
            temp->prev = head;
            head->next = temp;
            mp[key] = temp;
        } else {
            if (curr >= size) {
                Node* its = tail->prev;
                Node* prev = its->prev;
                Node* next = its->next;
                prev->next = next;
                next->prev = prev;
                mp.erase(its->key);
                delete its;

                Node* temp = new Node(key, value);
                head->next->prev = temp;
                temp->next = head->next;
                temp->prev = head;
                head->next = temp;
                mp[key] = temp;
            } else {
                ++curr;
                Node* temp = new Node(key, value);
                head->next->prev = temp;
                temp->next = head->next;
                temp->prev = head;
                head->next = temp;
                mp[key] = temp;
            }
        }
    }
};