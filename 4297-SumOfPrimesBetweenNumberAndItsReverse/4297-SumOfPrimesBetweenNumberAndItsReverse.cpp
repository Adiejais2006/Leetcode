// Last updated: 7/18/2026, 1:58:41 PM
class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }

    int reversen(int n){
        int rem=0;
        while(n>0){
            rem=rem*10+(n%10);
            n/=10;
        }
        return rem;
    }
    int sumOfPrimesInRange(int n) {
        int rev=reversen(n);
        int count=0;
        int low=min(n,rev);
        int high=max(n,rev);
        for(int i=low;i<=high;i++){
            if(isprime(i)){
                count+=i;
            }
        }
        return count;
    }
};