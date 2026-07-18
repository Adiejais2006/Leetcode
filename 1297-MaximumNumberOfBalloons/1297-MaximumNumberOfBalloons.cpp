// Last updated: 7/18/2026, 2:02:19 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;

        for (char c : text)
            freq[c]++;

        return min(
            {freq['b'], freq['a'], freq['l'] / 2, freq['o'] / 2, freq['n']});
    }
};