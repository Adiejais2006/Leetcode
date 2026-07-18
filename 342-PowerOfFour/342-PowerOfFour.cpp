// Last updated: 7/18/2026, 2:04:53 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
       if(n<=0) return false;
       while(!(n%4)){
        n/=4;
       } 
       return n==1;
    }
};