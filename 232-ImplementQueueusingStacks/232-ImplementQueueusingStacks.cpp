// Last updated: 9/5/2026, 3:58:39 PM
1class MyQueue {
2    stack<int> a;
3    stack<int> b;
4    int size;
5
6public:
7    MyQueue() { size = 0; }
8    void push(int x) {
9        a.push(x);
10        size++;
11    }
12    int pop() {
13        if (b.empty()) {
14            while (!a.empty()) {
15                b.push(a.top());
16                a.pop();
17            }
18        }
19        int top = b.top();
20        b.pop();
21        size--;
22        return top;
23    }
24    int peek() {
25        if (b.empty()) {
26            while (!a.empty()) {
27                b.push(a.top());
28                a.pop();
29            }
30        }
31        return b.top();
32    }
33    bool empty() { return size == 0; }
34};
35
36/**
37 * Your MyQueue object will be instantiated and called as such:
38 * MyQueue* obj = new MyQueue();
39 * obj->push(x);
40 * int param_2 = obj->pop();
41 * int param_3 = obj->peek();
42 * bool param_4 = obj->empty();
43 */