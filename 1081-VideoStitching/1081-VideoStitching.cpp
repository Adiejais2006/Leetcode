// Last updated: 7/18/2026, 2:02:39 PM
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        if (clips[0][0] != 0)
            return -1;
        int i = 0;
        int farthest = 0;
        int ans = 0;
        int currEnd = 0;
        int n = clips.size();
        while (currEnd < time) {
            while (i < n && clips[i][0] <= currEnd) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            if (farthest == currEnd)
                return -1;
            ans++;
            currEnd = farthest;
        }

        return ans;
    }
};