// Last updated: 7/18/2026, 2:07:54 PM
class Solution {  void func(int ind, string digits, string s, vector<string> &ans, string combos[]) {
       
        if(ind == digits.size()) {
         
            ans.push_back(s);
            return;
        }
       
        int digit = digits[ind] - '0';
        string value = combos[digit];
        
        for(int i = 0; i < combos[digit].size(); i++) {
            s.push_back(value[i]);
            func ( ind +1 , digits , s , ans , combos);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
       string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; 
        string s = ""; 
      
        func(0, digits, s, ans, combos);
        return ans; 
    }
};