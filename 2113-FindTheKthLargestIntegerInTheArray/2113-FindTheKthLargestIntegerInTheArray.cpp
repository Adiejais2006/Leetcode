// Last updated: 7/18/2026, 2:01:11 PM
class Solution {
public:
    struct cmp {
        bool operator()(const string& a, const string& b) {
            if (a.size() != b.size())
                return a.size() > b.size();

            return a > b;
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {

        priority_queue<string, vector<string>, cmp> pq;

        for (auto& num : nums) {
            pq.push(num);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};