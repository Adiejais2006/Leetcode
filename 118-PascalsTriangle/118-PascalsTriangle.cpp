// Last updated: 7/18/2026, 2:06:24 PM
class Solution {    vector<int> generaterow(int n) {
        vector<int> temp;
        for (int i = 0; i <= n; i++) {
            int ans = 1 ;
            for (int j = 0; j < i; j++) {
                ans =ans *(n-j);
                ans = ans/(j+1);
            }
            temp.push_back(ans);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> ans;
         int n = numRows;
        for (int i = 0; i < n; i++) {
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};