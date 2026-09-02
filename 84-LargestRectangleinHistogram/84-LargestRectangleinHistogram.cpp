// Last updated: 9/2/2026, 9:36:18 PM
1class Solution {
2    vector<int> ns(vector<int>& nums){
3        int n = nums.size();
4        vector<int>ans(n);
5        stack<int>st;
6        for(int i = n-1 ; i >=0 ; i--){
7            while(!st.empty() &&  nums[st.top()]>=nums[i]) {
8                st.pop();
9            }
10            if(st.empty()) ans[i] = n ;
11            else ans[i] = st.top(); 
12            st.push(i);
13        }   
14        return ans ;    
15    }
16    vector<int> ps(vector<int>& nums){
17        int n = nums.size();
18        vector<int>ans(n);
19        stack<int>st;
20        for(int i = 0 ; i <n  ; i++){
21            while(!st.empty() &&  nums[st.top()]>=nums[i]) {
22                st.pop();
23            }
24            if(st.empty()) ans[i] = -1 ;
25            else ans[i] = st.top(); 
26            st.push(i);
27        }   
28        return ans ;    
29    }
30public:
31    int largestRectangleArea(vector<int>& nums) {
32        int n = nums.size();
33        vector<int> nse = ns(nums);
34        vector<int> pse = ps(nums);
35        int ans = 0 ;
36        for(int i = 0  ; i < n ; i++){
37            int w = nse[i] - pse[i] - 1 ;
38            int h = nums[i];
39            int area = h*w;
40            ans = max( ans , area);
41        }
42        return ans ;
43    }
44};