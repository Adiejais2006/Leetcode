// Last updated: 10/18/2026, 10:31:31 PM
1class Solution {
2public:
3    vector<string> findRepeatedDnaSequences(string s) {
4        vector<string> ans;
5        int n = s.size();
6        if (n < 10)
7            return ans;
8        unordered_map<string, int> mpp;
9        string temp = "";
10        int l = 0;
11        int r = 0;
12        for (r; r < 10; r++) {
13            temp += s[r];
14        }
15        mpp[temp]++;
16        while (r < n) {
17            temp.erase(temp.begin());
18            temp += s[r];
19                mpp[temp]++;
20            if (mpp.find(temp) != mpp.end()) {
21                if(mpp[temp]==2)
22                ans.push_back(temp);
23            }
24            l++;
25            r++;
26        }
27        return ans;
28    }
29};  