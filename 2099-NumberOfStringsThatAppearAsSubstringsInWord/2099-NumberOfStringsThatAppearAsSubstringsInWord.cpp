// Last updated: 7/18/2026, 2:01:13 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0 ;
        for(auto it:patterns){
            if(word.find(it)!=string::npos){
                ans++;
            }

        }
        return ans ;
    }
};