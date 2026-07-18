// Last updated: 7/18/2026, 1:59:59 PM
class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> primeScore(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int p = 2; 1LL * p * p <= x; p++) {
                if (x % p == 0) {
                    primeScore[i]++;
                    while (x % p == 0) x /= p;
                }
            }

            if (x > 1) primeScore[i]++;
        }

        vector<long long> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScore[st.top()] < primeScore[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScore[st.top()] <= primeScore[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        vector<pair<int, int>> order;

        for (int i = 0; i < n; i++)
            order.push_back({nums[i], i});

        sort(order.rbegin(), order.rend());

        long long ans = 1;

        for (auto &[val, idx] : order) {
            long long cnt = left[idx] * right[idx];
            long long take = min(1LL * k, cnt);

            ans = ans * modPow(val, take) % MOD;
            k -= take;

            if (k == 0) break;
        }

        return ans;
    }
};