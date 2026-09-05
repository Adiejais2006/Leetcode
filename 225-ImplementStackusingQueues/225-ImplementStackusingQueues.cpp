// Last updated: 9/5/2026, 5:32:23 PM
1class MyStack {
2    queue<int>q;
3public:
4    MyStack() {
5
6    }
7    void push(int x) {
8        q.push(x);
9        for(int i = 0 ; i < q.size()-1 ; i++){
10            q.push(q.front());
11            q.pop();
12        }
13    }
14    int pop() {
15        int c = q.front();
16        q.pop();
17        return c;
18    }  
19    int top() {
20        return q.front();
21    } 
22    bool empty() {
23        return q.empty();
24    }
25};
26
27