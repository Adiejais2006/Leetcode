// Last updated: 9/4/2026, 4:13:27 PM
1class MyCircularQueue {
2    vector<int> arr;
3    int k;
4    int front;
5    int rear;
6    int size;
7
8public:
9    MyCircularQueue(int k) {
10        rear = -1;
11        front = -1;
12        size = 0;
13        this->k = k;
14        arr.resize(k);
15    }
16
17    bool enQueue(int value) {
18        if (size == k)
19            return false;
20
21        if (size == 0) {
22            front = 0;
23            rear = 0;
24        } else {
25            rear = (rear + 1) % k;
26        }
27
28        arr[rear] = value;
29        size++;
30
31        return true;
32    }
33
34    bool deQueue() {
35        if (size == 0)
36            return false;
37
38        if (size == 1) {
39            front = -1;
40            rear = -1;
41        } else {
42            front = (front + 1) % k;
43        }
44
45        size--;
46
47        return true;
48    }
49
50    int Front() {
51        if (front != -1)
52            return arr[front];
53        return -1;
54    }
55
56    int Rear() {
57        if (rear != -1)
58            return arr[rear];
59        return -1;
60    }
61
62    bool isEmpty() {
63        return size == 0;
64    }
65
66    bool isFull() {
67        return size == k;
68    }
69};