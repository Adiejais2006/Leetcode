// Last updated: 7/18/2026, 2:00:09 PM
class Solution {
public:
    string removeTrailingZeros(string num) {
        while(!num.empty() && num.back()=='0') num.pop_back();
        return num;
    }
};