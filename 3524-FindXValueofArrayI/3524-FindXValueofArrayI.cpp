// Last updated: 9/21/2026, 9:53:15 AM
1int freq[5], freq2[5];
2class Solution {
3public:
4    static vector<long long> resultArray(vector<int>& nums, int k) {
5        const int n=nums.size();
6        if (k==1) return {1LL*n*(n+1)/2};
7        vector<long long> ans(k, 0);
8        memset(freq, 0, sizeof(int)*k);
9        for (int x: nums){
10            const int r=x%k;
11            memset(freq2, 0, sizeof(int)*k);
12            ans[r]++;
13            for (int j=0; j<k; j++){
14                const int prod=j*r%k;
15                freq2[prod]+=freq[j];
16                ans[prod]+=freq[j];
17            }
18            freq2[r]++;
19            memcpy(freq,freq2, sizeof(int)*k);
20        }
21        return ans;
22    }
23};