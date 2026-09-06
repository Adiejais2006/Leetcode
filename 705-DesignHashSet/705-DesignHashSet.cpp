// Last updated: 9/6/2026, 5:14:59 PM
1class MyHashSet {
2public:
3    int size;
4    vector<vector<int>>v;
5    int hashFunc(int key) {
6        return key%size;
7    }
8    MyHashSet() {
9        size=1009;
10        v.resize(size);        
11    }
12    
13    void add(int key) {
14        if(!contains(key)) {
15            int idx=hashFunc(key);
16            v[idx].push_back(key);
17        }
18    }
19    
20    void remove(int key) {
21        int idx=hashFunc(key);
22        auto it=find(v[idx].begin(),v[idx].end(),key);
23        if(it!=v[idx].end()) {
24            v[idx].erase(it);
25        }
26    }
27    
28    bool contains(int key) {
29        int idx=hashFunc(key);
30        return find(v[idx].begin(),v[idx].end(),key) !=v[idx].end();
31    }
32};
33
34