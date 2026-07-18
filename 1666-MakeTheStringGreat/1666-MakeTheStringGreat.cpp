// Last updated: 7/18/2026, 2:01:43 PM
class Solution {
public:
    string makeGood(string s) {

        string ans = "";

        for(char ch : s){

            if(!ans.empty()  && abs(ans.back() - ch) == 32){
                ans.pop_back();

            }
            else{
                ans.push_back(ch);
            }
        }

        return ans;
        
    }
};