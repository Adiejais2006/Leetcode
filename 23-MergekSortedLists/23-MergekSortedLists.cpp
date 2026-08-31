// Last updated: 9/1/2026, 12:49:49 AM
1class Solution {
2    struct comp {
3        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
4    };
5
6public:
7    ListNode* mergeKLists(vector<ListNode*>& lists) {
8        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
9        for (auto it : lists)
10            if (it != NULL)
11                pq.push(it);
12        ListNode* dummy = new ListNode(-1);
13        ListNode* newHead = dummy;
14        while (!pq.empty()) {
15
16            auto it = pq.top();
17            pq.pop();
18            ListNode* nextNode = new ListNode(it->val);
19            dummy->next = nextNode;
20            dummy = nextNode;
21            if (it->next != NULL)
22                pq.push(it->next);
23        }
24        return newHead->next;
25    }
26};