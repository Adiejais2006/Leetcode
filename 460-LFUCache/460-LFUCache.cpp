// Last updated: 9/1/2026, 12:31:07 AM
1class LFUCache {
2
3    class Node {
4    public:
5        int key;
6        int val;
7        int counter;
8
9        Node* next;
10        Node* prev;
11
12        Node(int k, int v) {
13            key = k;
14            val = v;
15            counter = 1;
16            next = NULL;
17            prev = NULL;
18        }
19    };
20
21    class DLL {
22    public:
23        Node* head;
24        Node* tail;
25
26        DLL() {
27            head = new Node(-1, -1);
28            tail = new Node(-1, -1);
29
30            head->next = tail;
31            tail->prev = head;
32        }
33
34        void insertAfterHead(Node* node) {
35            Node* nextNode = head->next;
36
37            head->next = node;
38            node->prev = head;
39
40            node->next = nextNode;
41            nextNode->prev = node;
42        }
43
44        void deleteNode(Node* node) {
45            Node* prevNode = node->prev;
46            Node* nextNode = node->next;
47
48            prevNode->next = nextNode;
49            nextNode->prev = prevNode;
50        }
51
52        Node* removeLast() {
53            if (tail->prev == head)
54                return NULL;
55
56            Node* node = tail->prev;
57
58            deleteNode(node);
59
60            return node;
61        }
62    };
63
64    int cap;
65    int minFreq;
66
67    unordered_map<int, Node*> keyNode;
68    unordered_map<int, DLL> freqList;
69
70    void increaseFreq(Node* node) {
71
72        int freq = node->counter;
73
74        freqList[freq].deleteNode(node);
75
76        if (freq == minFreq &&
77            freqList[freq].head->next == freqList[freq].tail) {
78            minFreq++;
79        }
80
81        node->counter++;
82
83        freqList[node->counter].insertAfterHead(node);
84    }
85
86public:
87
88    LFUCache(int capacity) {
89        cap = capacity;
90        minFreq = 0;
91    }
92
93    int get(int key) {
94
95        if (keyNode.find(key) == keyNode.end())
96            return -1;
97
98        Node* node = keyNode[key];
99
100        increaseFreq(node);
101
102        return node->val;
103    }
104
105    void put(int key, int value) {
106
107        if (cap == 0)
108            return;
109
110        
111        if (keyNode.find(key) != keyNode.end()) {
112
113            Node* node = keyNode[key];
114
115            node->val = value;
116
117            increaseFreq(node);
118
119            return;
120        }
121
122     
123        if (keyNode.size() == cap) {
124
125            Node* last = freqList[minFreq].removeLast();
126
127            keyNode.erase(last->key);
128
129            delete last;
130        }
131
132        
133        Node* node = new Node(key, value);
134
135        keyNode[key] = node;
136
137        freqList[1].insertAfterHead(node);
138
139        minFreq = 1;
140    }
141};