// Last updated: 11/3/2026, 11:55:42 PM
1
2class Solution {
3private:
4    bool solve(vector<int>& nums, vector<int>& bucket, int target, int idx){
5
6        // Base case
7        if(idx == nums.size()){
8            return true;
9        }
10
11        for(int i = 0; i < bucket.size(); i++){
12
13            // check if current element fits the target
14            if(bucket[i] + nums[idx] <= target){
15
16                bucket[i] += nums[idx];
17
18                if(solve(nums, bucket, target, idx + 1)){
19                    return true;
20                }
21
22                // Backtrack
23                bucket[i] -= nums[idx];
24            }
25
26            // Avoid trying identical empty buckets
27            if(bucket[i] == 0) break;
28        }
29
30        return false;
31    }
32
33public:
34    bool canPartitionKSubsets(vector<int>& nums, int k) {
35
36        int sum = accumulate(nums.begin(), nums.end(), 0);
37
38        // edge case
39        if(sum % k != 0) return false;
40
41        int target = sum / k;
42
43        sort(nums.rbegin(), nums.rend());
44
45        if(nums[0] > target) return false;
46
47        vector<int> bucket(k, 0);
48
49        return solve(nums, bucket, target, 0);
50    }
51};