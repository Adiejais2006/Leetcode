// Last updated: 8/31/2026, 6:42:18 PM
1class Solution {
2public:
3    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
4        int Min = 100000, i = 1;
5        int c[2] = {0, 0};
6        auto prev = head, curr = head->next, nxt = head->next->next;
7        auto isCrit = [&]() {
8            auto x = prev->val, y = curr->val, z = nxt->val;
9            return (x < y && y > z) || (x > y && y < z);
10        };
11        while (nxt) {
12            if (isCrit()) {
13                if (c[0]) Min = min(Min, i - c[c[1] > 0]);
14                c[c[0] > 0] = i;
15            }
16            prev = curr; curr = nxt;
17            nxt = nxt->next; i++;
18        }
19        if (c[1]) return {Min, c[1] - c[0]};
20        return {-1, -1};
21    }
22};