// Last updated: 7/18/2026, 2:05:55 PM
class Solution {
public:
    string reverseWords(string s) {
       int n = s.size();
        int i = 0, j = 0, start = 0, end = 0;
        reverse(s.begin(), s.end()); 
        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            if (j >= n) break;
            start = i; 
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }
            end = i - 1;
            reverse(s.begin() + start, s.begin() + end + 1);
            s[i++] = ' ';
        }
        if (i > 0 && s[i - 1] == ' ') i--;
        return s.substr(0, i);  
    }
};