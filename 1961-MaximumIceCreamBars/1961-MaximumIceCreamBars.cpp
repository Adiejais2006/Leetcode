// Last updated: 7/18/2026, 2:01:28 PM
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0;
        vector<int> freq(100001, 0);
        for (int cost : costs)
            freq[cost]++;
        for (int i = 1; i <= 100000; i++) {
            if (freq[i] == 0)
                continue;
            int bars = min(freq[i], coins / i);
            cnt += bars;
            coins -= bars * i;
            if (coins == 0)
                break;
        }
        return cnt;
    }
};