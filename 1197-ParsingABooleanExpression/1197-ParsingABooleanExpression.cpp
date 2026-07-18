// Last updated: 7/18/2026, 2:02:28 PM
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (auto it : expression) {
            if (it == ',' || it == '(')
                continue;
            else if (it != ')')
                st.push(it);
            else {
                int t = 0;
                int f = 0;
                while (!st.empty() && st.top() != '!' && st.top() != '|' &&
                       st.top() != '&') {
                    if (st.top() == 't')
                        t++;
                    else
                        f++;

                    st.pop();
                }
                char ch = st.top();
                st.pop();
                if (ch == '&') {
                    if (f)st.push('f');
                    else st.push('t');
                }
                else if(ch=='!'){
                    if(f) st.push('t');
                    else st.push('f');
                }
                else if (ch=='|'){
                    if(t) st.push('t');
                    else st.push('f');
                }
                
            }
        }

        return st.top()=='t';
    }
};