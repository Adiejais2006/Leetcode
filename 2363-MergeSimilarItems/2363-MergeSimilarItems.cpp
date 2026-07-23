// Last updated: 7/24/2026, 12:23:13 AM
1class Solution {
2public:
3    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
4        vector<vector<int>>v;
5        int m=items1.size();
6        int n=items2.size();
7        sort(items1.begin(),items1.end());
8        sort(items2.begin(),items2.end());
9        int i=0,j=0;
10        while(i<m && j<n) {
11            if(items1[i][0]==items2[j][0]) {
12                items1[i][1]+=items2[j][1];
13                v.push_back(items1[i]);
14                i++;j++;
15            }
16            else if(items1[i][0]>items2[j][0]) v.push_back(items2[j++]);
17            else if(items1[i][0]<items2[j][0]) v.push_back(items1[i++]);
18        }
19        while(i<m) v.push_back(items1[i++]);
20        while(j<n) v.push_back(items2[j++]);
21        return v;                
22    }
23};