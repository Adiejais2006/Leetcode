// Last updated: 7/18/2026, 1:58:37 PM
class Solution {
public:
    bool consecutiveSetBits(int n) {
      int dingu = n& (n>>1);
        return ( dingu>0) && ((dingu & (dingu-1))==0);
        
    }
};