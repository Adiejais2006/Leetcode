// Last updated: 7/18/2026, 2:08:04 PM
class Solution {
    bool isValid(char s) {
        if (s >= '0' && s <= '9')
            return true;
        return false;
    }
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool neg = false;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ')
                i++;
            else
                break;
        }
        if (i < s.size() && s[i] == '-') {
            neg = true;
            i++;
        } 
        else if (i < s.size() && s[i] == '+') {
            i++;
        }
        while (i < s.size() && s[i] == '0') {
            i++;
        }
        while (i < s.size()) {
            if (isValid(s[i])) {
                int digit = s[i] - '0';
                if (ans > (LLONG_MAX - digit) / 10)
                    return neg ? INT_MIN : INT_MAX;
                ans = ans * 10 + digit;
                if (!neg && ans > INT_MAX)
                    return INT_MAX;
                if (neg && ans > 2147483648LL)
                    return INT_MIN;
            } 
            else {
                break;
            }
            i++;
        }
        if (neg)return -ans;
        return ans;
    }
};