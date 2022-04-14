class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
        
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node *temp){
        node *dummy=head->next;
        head->next=temp;
        temp->next=dummy;
        temp->prev=head;
        dummy->prev=temp;
    }
    void delNode(node *temp){
        node* tempnext=temp->next;
        node* tempprev=temp->prev;
        tempnext->prev=tempprev;
        tempprev->next=tempnext;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *res=m[key];
            m.erase(key);
            int ans=res->val;
            delNode(res);
            addNode(res);
            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *exist=m[key];
            m.erase(key);
            delNode(exist);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */