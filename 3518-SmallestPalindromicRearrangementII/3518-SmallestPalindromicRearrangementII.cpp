// Last updated: 7/29/2026, 7:24:42 PM
1constexpr int INF=1e6+1, N=24;
2int C[N][N]={{0}};
3
4constexpr void Pascal() {
5    if (C[0][0]==1) return; // computed once
6    C[0][0]=1;
7    for (int i=1; i<N; i++) {
8        C[i][0]=C[i][i]=1;
9        for (int j=1; j<=i/2; j++) {
10            C[i][j]=C[i][i-j]=C[i-1][j-1]+C[i-1][j];
11        }
12    }
13}
14
15class Solution {
16public:
17    static int comb(int n, int k) {
18        if (n<N) return C[n][k];//  look at the table
19        if (2*k>n) k=n-k;// C(n, n-k)=C(n, k)
20        int64_t ans=1;
21        for (int i=1; i<=k; i++) {
22            ans=ans*(n-i+1)/i;
23            if (ans>=INF) return INF;
24        }
25        return ans;
26    }
27
28    static int perm(const array<int, 26>& freq, int sz) {
29        int64_t ans=1;
30        for (int f : freq) {
31            if (f==0) continue;
32            ans*=comb(sz, f);
33            if (ans>=INF) return INF;
34            sz-=f;
35        }
36        return ans;
37    }
38
39    static string smallestPalindrome(string& s, int k) {
40        Pascal();
41        const int n=s.size(), n0=n/2;
42        array<int, 26> freq={0};
43        for (int i=0; i<n0; i++)
44            freq[s[i]-'a']++;
45        
46        int total=perm(freq, n0);
47        if (k>total) return "";
48
49        string left;
50        left.reserve(n);
51        int sz=n0;
52        for (int i=0; i<n0; i++) {
53            for (int c=0; c<26; c++) {
54                if (freq[c]==0) continue;
55                freq[c]--;
56                int cnt=perm(freq, --sz);
57                if (cnt>=k) {
58                    left.push_back('a' + c);
59                    break;
60                } 
61                else {
62                    k -= cnt;
63                    freq[c]++;// backtrack
64                    sz++;
65                }
66            }
67        }
68
69        string right=left;
70        reverse(right.begin(), right.end());
71        if (n&1) left.push_back(s[n/2]);
72        left.append(right);
73        return left;
74    }
75};
76
77auto init = []() {
78    ios::sync_with_stdio(false);
79    cin.tie(nullptr);
80    cout.tie(nullptr);
81    return 'c';
82}();
83