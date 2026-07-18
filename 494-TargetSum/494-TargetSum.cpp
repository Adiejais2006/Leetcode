// Last updated: 7/18/2026, 2:04:19 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        // ye peorblem same subset sum with partition with differences waala hai 
        int n = arr.size();
         int sum = 0;
        for (auto it : arr) sum += it;
        if (sum - target < 0 || (sum - target) % 2 != 0) return 0;
        int K = (sum - target) / 2;
        int mod = 1e9 + 7;
        vector<int> before(K + 1, 0);
        vector<int> curr(K + 1, 0);

        if (arr[0] == 0) {
            before[0] = 2;
        } else
            before[0] = 1;
        if (arr[0] != 0 && arr[0] <= K) before[arr[0]] = 1;
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= K; target++) {
                int pick = 0;
                if (arr[ind] <= target) pick = before[target - arr[ind]];

                int notpick = before[target];

                curr[target] = (pick + notpick) % mod;
            }
            before = curr;
        }
        return before[K];
    }
};