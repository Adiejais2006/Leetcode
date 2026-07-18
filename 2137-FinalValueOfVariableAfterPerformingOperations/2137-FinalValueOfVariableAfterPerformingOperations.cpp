// Last updated: 7/18/2026, 2:01:10 PM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        for (auto it : operations) {
            
            if(it[1]=='+') ans++;
            else ans--;
        }

        return ans;
    }
};