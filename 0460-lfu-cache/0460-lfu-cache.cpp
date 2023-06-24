class Node{
public:
    int val;
    int key;
    int count;
    Node*prev;
    Node*next;
    Node(int key, int val){
        this->key=key;
        this->val=val;
        count=1;
    }
};

class List{
public:
    int size;
    Node*head;
    Node*tail;
    List(){
        head=new Node(0, 0);
        tail=new Node(0, 0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void insert(Node* nn){
        tail->prev->next = nn;
        nn->prev = tail->prev;
        nn->next = tail;
        tail->prev = nn;
        size++;
    }

    void remove(Node* curr){
        Node*next=curr->next;
        Node*prev=curr->prev;
        prev->next=next;
        next->prev=prev;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*>keys;
    map<int, List*>freq;
    int minf;
    int size;
    int cap;
    LFUCache(int capacity) {
        minf=0;
        size=0;
        cap=capacity;
    }

    void update(Node* curr){
        keys.erase(curr->key);
        freq[curr->count]->remove(curr);
        if(curr->count==minf && freq[curr->count]->size==0) minf++;
        List* nextList=new List();
        if(freq.find(curr->count+1)!=freq.end())nextList=freq[curr->count+1];
        curr->count++;
        nextList->insert(curr);
        freq[curr->count]=nextList;
        keys[curr->key]=curr;
    }
    
    int get(int key) {
        if(keys.find(key)==keys.end()) return -1;
        Node* curr=keys[key];
        update(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(keys.find(key)==keys.end())
        {
            if(size<cap)
            {
                size++;
                minf=1;
                List* listn = new List();
                if(freq.find(minf)!=freq.end())
                    listn=freq[minf];
                Node*curr= new Node(key, value);
                listn->insert(curr);
                keys[key]=curr;
                freq[minf]=listn;
            }
            else
            {
                List* listnn = freq[minf];
                keys.erase(listnn->head->next->key);
                listnn->remove(listnn->head->next);
                //removal
                minf=1;
                size++;
                List* listn = new List();
                if(freq.find(minf)!=freq.end())
                    listn=freq[minf];
                Node*curr= new Node(key, value);
                listn->insert(curr);
                keys[key]=curr;
                freq[minf]=listn;
            }
        }
        else
        {
            Node* curr = keys[key];
            curr->val = value;
            update(curr);
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */