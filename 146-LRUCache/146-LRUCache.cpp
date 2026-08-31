// Last updated: 8/31/2026, 11:45:44 PM
1class LRUCache {
2
3    class Node {
4    public:
5        int key;
6        int val;
7        Node* next;
8        Node* prev;
9
10        Node(int k, int v) {
11            key = k;
12            val = v;
13            next = NULL;
14            prev = NULL;
15        }
16    };
17
18    int cap;
19    Node* head;
20    Node* tail;
21    unordered_map<int, Node*> mpp;
22
23    void insertAfterHead(Node* node) {
24        Node* temp = head->next;
25
26        node->next = temp;
27        node->prev = head;
28
29        head->next = node;
30        temp->prev = node;
31    }
32
33    void deleteNode(Node* node) {
34        Node* forward = node->next;
35        Node* backward = node->prev;
36
37        backward->next = forward;
38        forward->prev = backward;
39    }
40
41public:
42
43    LRUCache(int capacity) {
44        cap = capacity;
45
46        head = new Node(-1, -1);
47        tail = new Node(-1, -1);
48
49        head->next = tail;
50        tail->prev = head;
51    }
52
53    int get(int key) {
54
55        if (mpp.find(key) == mpp.end())
56            return -1;
57
58        Node* node = mpp[key];
59
60        deleteNode(node);
61        insertAfterHead(node);
62
63        return node->val;
64    }
65
66    void put(int key, int value) {
67
68        if (mpp.find(key) != mpp.end()) {
69
70            Node* node = mpp[key];
71
72            node->val = value;
73
74            deleteNode(node);
75            insertAfterHead(node);
76
77        } else {
78
79            if (mpp.size() == cap) {
80
81                Node* last = tail->prev;
82
83                deleteNode(last);
84
85                mpp.erase(last->key);
86
87                delete last;
88            }
89
90            Node* newNode = new Node(key, value);
91
92            insertAfterHead(newNode);
93
94            mpp[key] = newNode;
95        }
96    }
97};