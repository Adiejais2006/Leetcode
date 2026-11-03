// Last updated: 11/3/2026, 1:36:05 PM
1class LRUCache {
2    int size;
3    struct Node {
4        int key, val;
5        Node* next;
6        Node* prev;
7
8        Node(int k, int v) {
9            key = k;
10            val = v;
11            next = NULL;
12            prev = NULL;
13        }
14    };
15    Node* head;
16    Node* tail;
17    unordered_map<int, Node*> mpp;
18    void insertafterhead(Node* node) {
19        Node* headnext = head->next;
20        head->next = node;
21        node->next = headnext;
22        headnext->prev = node;
23        node->prev = head;
24    }
25
26    void deleteNode(Node* node) {
27        Node* nodeNext = node->next;
28        Node* nodePrev = node->prev;
29        nodePrev->next = nodeNext;
30        nodeNext->prev = nodePrev;
31    }
32
33public:
34    LRUCache(int capacity) {
35        size = capacity;
36        head = new Node(-1, -1);
37        tail = new Node(-1, -1);
38        head->next = tail;
39        tail->prev = head;
40    }
41
42    int get(int key) {
43        if (mpp.find(key) == mpp.end())
44            return -1;
45        Node* node = mpp[key];
46        deleteNode(node);
47        insertafterhead(node);
48        return node->val;
49    }
50    void put(int key, int value) {
51        if (mpp.find(key) != mpp.end()) {
52            Node* node = mpp[key];
53            node->val = value;
54            deleteNode(node);
55            insertafterhead(node);
56
57        } else {
58            if (mpp.size() == size) {
59                Node* last = tail->prev;
60                deleteNode(last);
61                mpp.erase(last->key);
62                delete last;
63            }
64            Node* newNode = new Node(key, value);
65            insertafterhead(newNode);
66            mpp[key] = newNode;
67        }
68    }
69};
70
71/**
72 * Your LRUCache object will be instantiated and called as such:
73 * LRUCache* obj = new LRUCache(capacity);
74 * int param_1 = obj->get(key);
75 * obj->put(key,value);
76 */