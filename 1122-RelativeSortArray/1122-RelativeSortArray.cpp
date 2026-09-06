// Last updated: 9/6/2026, 5:19:22 PM
1class Solution {
2public:
3    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
4        vector<int>count(1001,0);
5        for(int num : arr1){
6            count[num]++;
7        }
8        vector<int>res;
9        res.reserve(arr1.size());
10        for(int num: arr2){
11            while(count[num]>0){
12                res.push_back(num);
13                count[num]--;
14            }
15
16        }
17        for(int i=0;i<=1000;i++){
18            while(count[i]>0){
19                res.push_back(i);
20                count[i]--;
21            }
22        }
23        return res;
24        
25    }
26};