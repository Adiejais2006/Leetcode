// Last updated: 9/4/2026, 4:54:42 PM
1class RecentCounter {
2    queue<int> q;
3
4public:
5    RecentCounter() {}
6
7    int ping(int t) {
8        q.push(t);
9        while (!q.empty() && q.front() < t-3000)
10            q.pop();
11        return q.size();
12    }
13};
14
15/**
16 * Your RecentCounter object will be instantiated and called as such:
17 * RecentCounter* obj = new RecentCounter();
18 * int param_1 = obj->ping(t);
19 */