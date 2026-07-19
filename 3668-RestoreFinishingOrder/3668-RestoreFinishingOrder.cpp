// Last updated: 7/19/2026, 1:45:21 PM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {

        unordered_set<int> st(friends.begin(), friends.end());
        vector<int> result;

        for (int num : order) {
            if (st.count(num)) {
                result.push_back(num);
            }
        }

        return result;
    }
};