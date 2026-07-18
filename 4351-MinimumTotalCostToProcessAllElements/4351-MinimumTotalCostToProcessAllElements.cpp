// Last updated: 7/18/2026, 1:58:26 PM
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long mod= 1000000007;
          long long curr=k;
        long long op=0;
        long long ans=0;

        for(int x:nums){
            if(curr<x){
                long long req=x-curr;
                long long take=(req+k-1)/k;

                long long p=take;
                long long q=2*op+take+1;

                if(p&1) q/=2;
                else p/=2;

                ans=(ans+(p%mod)*(q%mod))%mod;

                op+=take;
                curr+=take*1LL*k;
            }
            curr-=x;
        }
        return ans;
               
    }
};