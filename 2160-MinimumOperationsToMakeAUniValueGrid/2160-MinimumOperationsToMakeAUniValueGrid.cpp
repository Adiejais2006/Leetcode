// Last updated: 7/18/2026, 2:01:07 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for (auto &row : grid)
            for (int num : row)
                arr.push_back(num);

        int rem = arr[0] % x;
        for (int num : arr)
            if (num % x != rem)
                return -1;

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];

        long long ops = 0;
        for (int num : arr)
            ops += abs(num - median) / x;

        return ops;
    }
};