// Last updated: 8/20/2026, 8:36:04 PM
1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        vector<int> arr1, arr2;
5        arr1 = {nums[0]};
6        arr2 = {nums[1]};
7        for(int i = 2;i<nums.size();i++){
8            if(arr1.back() > arr2.back()){
9                arr1.push_back(nums[i]);
10            }else{
11                arr2.push_back(nums[i]);
12            }
13        }
14        for(auto it : arr2){
15            arr1.push_back(it);
16        }
17        return arr1;
18    }
19};