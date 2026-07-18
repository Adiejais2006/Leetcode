// Last updated: 7/18/2026, 2:00:33 PM
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cost = count(customers.begin(), customers.end(), 'Y');
        int minCost = cost, ans = 0;
        
        for (int j = 1; j <= n; j++) {
            if (customers[j-1] == 'Y') cost--;
            else cost++;
            
            if (cost < minCost) {
                minCost = cost;
                ans = j;
            }
        }
        return ans;
    }
};