// Last updated: 10/26/2026, 2:26:20 PM
    // in this problem idea is that nums[i]>0 thus as we expand
    // in left side value will always increase
    // initially it will be in range but later it will
    // go out of k thus we need to search for that index

    // now what we can do is that we mantain a prefix sum
    // and while searching we get sum from prefix array and
    // window size from pointers thus able to do it optimally
    int n=nums.length;
    long[] pref=new long[n+1];// 1-based indexing
    long res=0;
    for(int i=0;i<n;i++){
        pref[i+1]=nums[i]+pref[i];
        int low=0,high=i+1;
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            long val=(pref[i+1]-pref[mid])*(i+1-mid);
            if(val>=k){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }   
        res+=(i+1)-ans;
    }
    return res;