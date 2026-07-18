// Last updated: 7/18/2026, 4:49:47 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4         int lmax = 0; 
5        int rmax = 0 ;
6        int total = 0 ;
7        int l = 0 ;
8        int r=height.size()-1;
9        while(l<r){
10            if(height[l]<=height[r]){
11                if(lmax>height[l]){
12                    total+=lmax - height[l];
13                }
14                else{
15                    lmax= height[l];
16                }
17                l++;
18            }
19            else {
20                if(rmax>height[r]){
21                      total+=rmax - height[r];
22                }
23                else{
24                    rmax= height[r];
25                }
26                r--;
27            }
28        }
29
30
31        return total;
32    }
33};