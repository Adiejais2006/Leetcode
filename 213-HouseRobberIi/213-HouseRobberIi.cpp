// Last updated: 7/18/2026, 2:05:32 PM
class Solution { int func(vector<int>&money) {
        int prev1 = money[0];
        int prev2 = 0;
        for (int i = 1; i < money.size() ; i++) {
            int take = money[i] + ((i > 1) ? prev2 : 0);
            int nott = prev1;
            int cur = max(take, nott);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
public:
    int rob(vector<int>& money) {
            int n = money.size();
        if (n == 1) return money[0];
        vector<int>a;
        vector<int>b;
        for(int i = 0 ; i<n-1 ;i++) a.push_back(money[i]);
        for(int i = 1 ;i<n ;i++) b.push_back(money[i]);
        return max(func(b),func(a));
    }
};