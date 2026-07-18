// Last updated: 7/18/2026, 2:02:35 PM
class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;

        for(char ch : s){
            if(!st.empty() && st.top() == ch){
                st.pop();

            }
            else{
                st.push(ch);

            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};