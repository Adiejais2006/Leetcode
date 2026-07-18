// Last updated: 7/18/2026, 1:58:35 PM
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
            int start =  max( 1, n-k);
        int end = n+k;
         int sum=0;
        for ( int i = start ; i<=end;i++){
            if( (n & i) ==0)  sum+=i;
        }
        return sum;
    }
};