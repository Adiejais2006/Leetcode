// Last updated: 7/18/2026, 2:07:01 PM
class Solution {
public:
    int minDistance(string start, string target) {
         int n = start.size();
        int m = target.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {

            
            curr[0] = i;

            for (int j = 1; j <= m; j++) {

                if (start[i - 1] == target[j - 1]) {
                    curr[j] = prev[j - 1];
                } 
                else {
                    int del = prev[j];
                    int ins = curr[j - 1];
                    int rep = prev[j - 1];

                    curr[j] =
                        1 + min({del, ins, rep});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};