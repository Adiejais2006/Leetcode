// Last updated: 7/18/2026, 1:59:48 PM
class Solution {
    static bool a(int a, int b) { return a > b; }

public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < apple.size(); i++)
            sum += apple[i];
        sort(capacity.begin(), capacity.end(), a);
        for (int i = 0; i < capacity.size(); i++) {
            cnt++;
            sum = sum - capacity[i];
            if (sum <= 0)
                break;
        }
        return cnt;
    }
};