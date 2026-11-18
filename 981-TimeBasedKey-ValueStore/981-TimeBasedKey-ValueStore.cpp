// Last updated: 11/18/2026, 3:17:32 PM
1class TimeMap {
2    unordered_map<string, vector<pair<int, string>>> mpp;
3public:
4    TimeMap() {}
5    void set(string key, string value, int timestamp) {
6        mpp[key].push_back({timestamp, value});
7    }
8    string get(string key, int timestamp) {
9        auto& temp = mpp[key];
10        int n = temp.size();
11        int low = 0;
12        int high = n - 1;
13        string ans = "";
14        while(low<=high){
15             int mid =(low+(high-low)/2);
16             if(temp[mid].first>timestamp) high =mid-1;
17             else {
18                low=mid+1 ;
19                ans = temp[mid].second;
20             }
21        }
22        return ans;
23    }
24};
25
26/**
27 * Your TimeMap object will a instantiated and called as such:
28 * TimeMap* obj = new TimeMap();
29 * obj->set(key,value,timestamp);
30 * string param_2 = obj->get(key,timestamp);
31 */