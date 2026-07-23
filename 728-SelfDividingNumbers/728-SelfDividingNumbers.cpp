// Last updated: 7/24/2026, 12:29:47 AM
1class Solution {
2public:
3    vector<int> selfDividingNumbers(int left, int right) {
4        vector<int> result;
5        while (left <= right) 
6        {
7            int num = left;
8            bool isSelfDividingNumber = true;
9            while (num != 0) 
10            {
11                int digit = num % 10;
12                num /= 10;
13
14                if (digit == 0 || left % digit != 0) 
15                {
16                    isSelfDividingNumber = false;
17                    break;
18                }
19            }
20            if (isSelfDividingNumber)
21                result.push_back(left);
22
23            left++;
24        }
25
26        return result;
27    }
28};