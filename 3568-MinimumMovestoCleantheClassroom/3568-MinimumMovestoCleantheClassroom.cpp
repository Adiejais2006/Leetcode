// Last updated: 9/1/2026, 11:52:12 AM
1class Solution {
2public:
3    int minMoves(vector<string>& classroom, int energy) {
4        int m = classroom.size();
5        int n = classroom[0].size();
6
7        int sr = -1, sc = -1;
8        int cnt = 0;
9
10    
11        vector<vector<int>> id(m, vector<int>(n, -1));
12
13        for(int i = 0; i < m; i++){
14            for(int j = 0; j < n; j++){
15                if(classroom[i][j] == 'S'){
16                    sr = i;
17                    sc = j;
18                }
19                if(classroom[i][j] == 'L'){
20                    id[i][j] = cnt++;
21                }
22            }
23        }
24
25        int masks = 1 << cnt;
26        int fullMask = masks - 1;
27
28        
29        vector<vector<vector<int>>> best(
30            m,
31            vector<vector<int>>(
32                n,
33                vector<int>(masks, -1)
34            )
35        );
36
37        struct State {
38            int r, c;
39            int mask;
40            int en;
41            int dist;
42        };
43
44        queue<State> q;
45        q.push({sr, sc, 0, energy, 0});
46        best[sr][sc][0] = energy;
47
48        int dr[] = {-1, 1, 0, 0};
49        int dc[] = {0, 0, -1, 1};
50
51        while(!q.empty()){
52            State cur = q.front();
53            q.pop();
54
55            int r = cur.r;
56            int c = cur.c;
57            int mask = cur.mask;
58            int en = cur.en;
59            int dist = cur.dist;
60
61           
62            if(mask == fullMask){
63                return dist;
64            }
65           
66            if(en == 0){
67                continue;
68            }
69
70            for(int d = 0; d < 4; d++){
71                int nr = r + dr[d];
72                int nc = c + dc[d];
73
74              
75                if(nr < 0 || nr >= m || nc < 0 || nc >= n){
76                    continue;
77                }
78
79              
80                if(classroom[nr][nc] == 'X'){
81                    continue;
82                }
83
84                int newEn = en - 1;
85                int newMask = mask;
86
87               
88                if(classroom[nr][nc] == 'L'){
89                    newMask |= (1 << id[nr][nc]);
90                }
91
92               
93                if(classroom[nr][nc] == 'R'){
94                    newEn = energy;
95                }
96
97              
98                if(best[nr][nc][newMask] >= newEn){
99                    continue;
100                }
101
102                best[nr][nc][newMask] = newEn;
103                q.push({nr, nc, newMask, newEn, dist + 1});
104            }
105        }
106        return -1;
107    }
108};