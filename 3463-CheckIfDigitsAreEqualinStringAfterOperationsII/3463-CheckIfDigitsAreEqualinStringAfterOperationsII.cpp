// Last updated: 11/6/2026, 5:07:17 PM
1using int3 = array<int, 3>; // (y, a, b) where x = y * 2^a * 5^b and gcd(y,10) = 1
2
3int3 C[100000];
4int inv10[10]={0, 1, 0, 7, 0, 0, 0, 3, 0, 9};// inv10[x]*x=1 (mod 10) for x coprime to 10
5
6class Solution {
7public:
8    int3 factor(int x) {
9        int a = countr_zero((unsigned)x);
10        x >>= a;
11        int b = 0;
12        while (x % 5 == 0) {
13            x /= 5;
14            b++;
15        }
16        return {x % 10, a, b}; // Only keep mod 10 for y
17    }
18
19    int3 inverse(const int3& x) {
20        int x0 = x[0], a = x[1], b = x[2];
21        int x0_inv = inv10[x0];
22        return {x0_inv, -a, -b};
23    }
24
25    int3 mult(const int3& x, const int3& y) {
26        return {x[0]*y[0]%10, x[1]+y[1], x[2]+y[2]};
27    }
28
29    int toInt(const int3& x) { // mod 10
30        if (x[1] >= 1 && x[2] >= 1) return 0;
31        if (x[2] >= 1) return 5;
32        int B[4] = {6, 2, 4, 8}; // 2^x(mod 10) cycle
33        if (x[1] == 0) return x[0];
34        int B2 = B[x[1] % 4]; // 
35        return x[0] * B2 % 10;
36    }
37
38    void compute_comb(int N) {
39        C[0] = {1, 0, 0}; 
40        if (N == 0) return; // Prevent C[N] access if N=0
41        C[N] = {1, 0, 0}; 
42
43        for (int k = 1; k <= N/2; k++) {
44            int3 P = factor(N-k + 1);
45            int3 Q = inverse(factor(k));
46            C[k]=C[N-k] = mult(mult(C[k-1], P), Q);
47        }
48    }
49
50    bool hasSameDigits(string& s) {
51        int n = s.size();
52
53        fill(C, C+(n-2), int3{0, 0, 0}); // Prevent overflow
54        compute_comb(n-2);
55
56        int sum=0;
57        for (int i=0; i <= n-2; i++) {
58            int C_val= (toInt(C[i])*(s[i]-s[i+1]))%10;
59            sum=(sum+C_val+10) % 10; // Ensure non-negative
60        }
61
62     //   cout << sum << endl;
63        return sum == 0;
64    }
65};