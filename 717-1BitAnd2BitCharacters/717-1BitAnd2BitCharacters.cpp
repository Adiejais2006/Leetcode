// Last updated: 7/18/2026, 2:03:39 PM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while (i < n-1) {
            if (bits[i] == 1)
                i += 1;
            i++;
        }

        if (i == n - 1)
            return true;
        return false;
    }
};