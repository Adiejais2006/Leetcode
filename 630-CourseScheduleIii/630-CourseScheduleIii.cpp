// Last updated: 7/18/2026, 2:03:55 PM
class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), comp);
        int time = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                pq.push(courses[i][0]);
                time += courses[i][0];
            } else if (!pq.empty() && pq.top() > courses[i][0]) {
                time -= pq.top();
                pq.pop();

                pq.push(courses[i][0]);
                time += courses[i][0];
            }
        }

        return pq.size();
    }
};