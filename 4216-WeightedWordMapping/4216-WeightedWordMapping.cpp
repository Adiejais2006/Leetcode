// Last updated: 7/18/2026, 1:58:52 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto it : words) {
            int sum = 0;
            for (auto ch : it) {
                sum += weights[ch - 'a'];
            }
            sum = sum % 26;
            char ch = 'z'-sum;
            ans += ch;
        }
        return ans;
    }
};