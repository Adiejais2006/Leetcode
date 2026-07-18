// Last updated: 7/18/2026, 1:59:18 PM
class Solution {
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) {
            return m;
        }

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // State:
        // 0..m-1      -> last move DOWN, ending at value v
        // m..2m-1     -> last move UP, ending at value v

        for (int v = 0; v < m; v++) {

            // DOWN -> UP
            for (int nv = v + 1; nv < m; nv++) {
                T[m + nv][v] = 1;
            }

            // UP -> DOWN
            for (int nv = 0; nv < v; nv++) {
                T[nv][m + v] = 1;
            }
        }

        vector<long long> init(S, 0);

        // Length = 2 initialization
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {

                if (a == b) continue;

                if (a < b) {
                    init[m + b]++;      // last move UP
                } else {
                    init[b]++;          // last move DOWN
                }
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] + P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};