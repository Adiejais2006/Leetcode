// Last updated: 7/18/2026, 2:04:30 PM
class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
          sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());
        int left = 0;
        int right = 0;
        int count = 0;
        while (left < Student.size() && right < Cookie.size()) {
            if (Student[left] <= Cookie[right]) {
                count++;
                right++;
                left++;
            } else {
                right++;
            }
        }
        return count;
    }
};