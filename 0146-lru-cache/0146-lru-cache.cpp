class node {
public:
    int key;
    int value;
    node* next;
    node*prev;
    node(int k,int v) {
        next = nullptr;
        prev = nullptr;
        key = k;
        value=v;
    }
};
class LRUCache {

    node* head ;
    node* tail ;
    int size;
    int curr;
    unordered_map<int,node*>mp;
public:
    LRUCache(int capacity) {
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next=tail;
        tail->prev=head;
        curr = 0;
        size = capacity;
    }
    void deleteNode(node*curr){
        node*prev=curr->prev;
        node*next=curr->next;
        prev->next=next;
        next->prev=prev;
        curr->prev=nullptr;
        curr->next=nullptr;
    }
    void addAtStart(node*curr){
        curr->next=head->next;
        head->next->prev=curr;
        curr->prev=head;
        head->next=curr;
    }

    int get(int key) {
        if(mp.count(key)){
            node*temp=mp[key];
            int ans=temp->value;
            deleteNode(temp);
            addAtStart(temp);
            return ans;
        }else return -1;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            node*temp=mp[key];
            temp->value=value;
            deleteNode(temp);
            addAtStart(temp);
            mp[key]=temp;
        }else{
            node*newNode=new node(key,value);
            if(curr+1<=size){
                addAtStart(newNode);
                ++curr;
            }else{
                node*remove=tail->prev;
                int key=remove->key;
                mp.erase(key);
                deleteNode(remove);
                addAtStart(newNode);
            }
            mp[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */