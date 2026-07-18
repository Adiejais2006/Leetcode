// Last updated: 7/18/2026, 2:01:15 PM
class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int minBalance = 0;

        for(char c : s) {
            if(c == '[') balance++;
            else balance--;

            minBalance = min(minBalance, balance);
        }

        return (-minBalance + 1) / 2;
    }
};