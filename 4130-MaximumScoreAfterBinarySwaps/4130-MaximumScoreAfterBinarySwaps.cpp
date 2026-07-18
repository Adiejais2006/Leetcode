// Last updated: 7/18/2026, 1:59:01 PM
class Solution {
public:
    long long maximumScore(vector<int>& arr, string s) {

        int n = arr.size();
        vector<int> oneee;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oneee.push_back(i);
            }
        }

        priority_queue<int> mp;
        long long ans = 0;
        int p = 0;

        for (int i = 0; i < oneee.size(); i++) {
            for (; p <= oneee[i]; p++) {
                mp.push(arr[p]);
            }
            ans += mp.top();
            mp.pop();
        }

        return ans;
    }
};
