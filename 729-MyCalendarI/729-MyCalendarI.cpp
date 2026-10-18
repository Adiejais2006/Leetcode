// Last updated: 10/18/2026, 10:38:11 PM
1class MyCalendar {
2public:
3    set<pair<int, int>> st;
4    MyCalendar() {
5        
6    }
7    bool book(int startTime, int endTime) {
8        auto it = st.lower_bound({startTime, endTime});
9        if(it != st.end() && it -> first < endTime){
10            return false;
11        }
12        if(it != st.begin()){
13            auto prevIt = prev(it);
14            if(startTime < prevIt -> second){
15                return false;
16            }
17        }
18        st.insert({startTime, endTime});
19        return true;
20    }
21};
22