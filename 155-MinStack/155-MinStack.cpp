// Last updated: 9/1/2026, 1:36:26 PM
1class MinStack {
2    class Node {
3    public:
4        int val;
5        int minVal;
6        Node* next;
7        Node(int value, int minimum) {
8            val = value;
9            minVal = minimum;
10            next = NULL;
11        }
12    };
13    Node* head = NULL;
14
15public:
16    MinStack() {}
17    void push(int value) {
18        if (head == NULL) {
19            head = new Node(value, value);
20        }
21        else {
22            Node* newNode = new Node(value, min(value, head->minVal));
23            newNode->next = head;
24            head = newNode;
25        }
26    }
27
28    void pop() {
29
30        if (head == NULL)
31            return;
32
33        Node* temp = head;
34        head = head->next;
35        delete temp;
36    }
37
38    int top() {
39
40        if (head == NULL)
41            return -1;
42
43        return head->val;
44    }
45
46    int getMin() {
47
48        if (head == NULL)
49            return -1;
50
51        return head->minVal;
52    }
53};