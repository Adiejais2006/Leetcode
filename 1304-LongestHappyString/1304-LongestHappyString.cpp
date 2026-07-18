// Last updated: 7/18/2026, 2:02:17 PM
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            int m = ans.size();

            if (m >= 2 && ans[m - 1] == ch1 && ans[m - 2] == ch1) {
                if (pq.empty()) break;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                cnt2--;

                if (cnt2) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            } else {
                ans += ch1;
                cnt1--;

                if (cnt1) pq.push({cnt1, ch1});
            }
        }

        return ans;
    }
};