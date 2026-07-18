// Last updated: 7/18/2026, 2:02:00 PM
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }
        int ans = 0;
        for (auto it : t) {
            if (mpp.find(it) != mpp.end() && mpp[it]>0) {

                mpp[it]--;      
            }
        }
       
        for(auto it:mpp) ans+=it.second;
        return ans;
    }
};