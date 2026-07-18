// Last updated: 7/18/2026, 1:59:31 PM
class Solution {
public:
    using ll = long long;
    struct Point {
        ll pos;  
        ll x, y;
    };
    ll getPos(ll side, ll x, ll y) {
        if (y == 0) return x;                  
        if (x == side) return side + y;       
        if (y == side) return 3LL * side - x;  
        return 4LL * side - y;                  
    }
    ll dist(Point& a, Point& b) {
        return llabs(a.x - b.x) + llabs(a.y - b.y);
    }
    bool can(vector<Point>& arr, int side, int k, ll need) {
        int n = arr.size();
        vector<Point> ext = arr;
        for (int i = 0; i < n; i++) {
            Point p = arr[i];
            p.pos += 4LL * side;
            ext.push_back(p);
        }
        vector<ll> positions(2 * n);
        for (int i = 0; i < 2 * n; i++) positions[i] = ext[i].pos;
        for (int start = 0; start < n; start++) {
            vector<int> chosen;
            chosen.push_back(start);
            int cur = start;
            while ((int)chosen.size() < k) {
                ll target = ext[cur].pos + need;

                int nxt = lower_bound(positions.begin() + cur + 1,
                                      positions.end(), target) - positions.begin();

                if (nxt >= start + n) break;

                chosen.push_back(nxt);
                cur = nxt;
            }
            if ((int)chosen.size() == k) {
                bool ok = true;
                for (int i = 0; i < k && ok; i++) {
                    for (int j = i + 1; j < k; j++) {
                        if (dist(ext[chosen[i]], ext[chosen[j]]) < need) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<Point> arr;
        for (auto& p : points) {
            arr.push_back({getPos(side, p[0], p[1]), p[0], p[1]});
        }
        sort(arr.begin(), arr.end(),
             [](Point& a, Point& b) { return a.pos < b.pos; });
        ll low = 0, high = 2LL * side, ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (can(arr, side, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};