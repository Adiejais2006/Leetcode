// Last updated: 7/18/2026, 2:00:49 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
         int ans;
        ans = start ^ goal;
        int count = 0;
        for(int i =0 ; i < 31 ; i++){
            if(ans&(1<<i)) count++;
        }
        return count;
    }
};