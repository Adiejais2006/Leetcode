// Last updated: 11/1/2026, 8:37:05 PM
1class TimeMap {
2    public:
3    unordered_map<string, vector<pair<int, string>>> mpp;
4public:
5    TimeMap() {
6    
7    }
8    void set(string key, string value, int timestamp) {
9        mpp[key].push_back({timestamp,value});
10    }
11
12    string get(string key, int timestamp) {
13        if(mpp.find(key)==mpp.end())return "";
14        auto &temp = mpp[key];
15        int n = temp.size();
16        int low = 0 ;
17        int high = n-1;
18        string ans ="";
19        while(low<=high){
20            int mid =(low+(high-low)/2);
21            if(temp[mid].first<=timestamp){
22                ans=temp[mid].second;
23                low = mid+1;
24            }
25            else high = mid-1;
26        }
27        return ans ;
28    }
29};
30
31/**
32 * Your TimeMap object will be instantiated and called as such:
33 * TimeMap* obj = new TimeMap();
34 * obj->set(key,value,timestamp);
35 * string param_2 = obj->get(key,timestamp);
36 */