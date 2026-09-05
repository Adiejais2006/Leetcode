// Last updated: 9/5/2026, 4:08:06 PM
1class MyStack {
2    queue<int>q;
3    int size ;
4public:
5    MyStack() {
6        size=0;
7    }
8    
9    void push(int x) {
10        q.push(x);
11        for(int i = 0 ; i < q.size()-1 ; i++){
12            q.push(q.front());
13            q.pop();
14        }
15    }
16    
17    int pop() {
18        int c = q.front();
19        q.pop();
20        return c;
21    }
22    
23    int top() {
24        return q.front();
25    }
26    
27    bool empty() {
28        return q.empty();
29    }
30};
31
32/**
33 * Your MyStack object will be instantiated and called as such:
34 * MyStack* obj = new MyStack();
35 * obj->push(x);
36 * int param_2 = obj->pop();
37 * int param_3 = obj->top();
38 * bool param_4 = obj->empty();
39 */