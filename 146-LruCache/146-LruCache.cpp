// Last updated: 7/18/2026, 2:05:58 PM
class LRUCache {    struct Node {
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;

    void insertAfterHead(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* forward = node->next;
        Node* backward = node->prev;

        backward->next = forward;
        forward->prev = backward;
    }

public:
    LRUCache(int capacity) {
         cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key_) {
         if (mpp.find(key_) == mpp.end()) return -1;

        Node* node = mpp[key_];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key_, int value) {
          if (mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->val = value;

            deleteNode(node);
            insertAfterHead(node);
        }
        else {
           
            if (mpp.size() == cap) {
                Node* lru = tail->prev;

                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }

           
            Node* newNode = new Node(key_, value);
            insertAfterHead(newNode);
            mpp[key_] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */