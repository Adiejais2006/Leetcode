// Last updated: 7/18/2026, 2:05:00 PM
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> s_count(10, 0), g_count(10, 0);
        
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                s_count[secret[i] - '0']++;
                g_count[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            cows += min(s_count[i], g_count[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};