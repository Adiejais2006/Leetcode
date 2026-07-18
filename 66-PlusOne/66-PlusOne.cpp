// Last updated: 7/18/2026, 2:07:05 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            int digit = 0;
            if (i == n - 1)
                digit = carry + digits[i] + 1;
            else
                digit = carry + digits[i];

            digits[i] = digit % 10;
            carry = digit / 10;
        }

        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};