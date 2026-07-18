// Last updated: 7/18/2026, 2:07:28 PM
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (n > 1) {
            string res = "";
            for (int i = 0; i < ans.size(); i++) {
                int cnt = 1;
                while (i+1 < ans.size() && ans[i] == ans[i + 1]) {
                    cnt++;
                    i++;
                }
                res += to_string(cnt) + ans[i];
            }
            ans = res;
            n--;
        }

        return ans;
    }
};