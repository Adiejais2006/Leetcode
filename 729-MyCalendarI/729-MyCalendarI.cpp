// Last updated: 11/10/2026, 10:07:43 PM
1class MyCalendar {
2    vector<pair<int, int>> nums;
3
4public:
5    MyCalendar() {}
6
7    bool book(int startTime, int endTime) {
8
9        for (auto it : nums) {
10            int s = it.first;
11            int e = it.second;
12            if(!(e<=startTime || endTime<=s)) return false;
13        }
14        nums.push_back({startTime,endTime});
15        return true;
16    }
17};
18
19/**
20 * Your MyCalendar object will be instantiated and called as such:
21 * MyCalendar* obj = new MyCalendar();
22 * bool param_1 = obj->book(startTime,endTime);
23 */