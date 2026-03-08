#include <bits/stdc++.h>
using namespace std;

long long dp[1000005][2], q[105];
long long MOD = 1000000007;

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long t, mx = 0;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> q[i];
        mx = max(mx, q[i]);
    }
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= mx; i++) {
        dp[i][0] = ((dp[i-1][1] % MOD) + (dp[i-1][0] * 2) % MOD) % MOD;
        dp[i][1] = ((dp[i-1][1] * 4) % MOD + (dp[i-1][0] % MOD)) % MOD;
    }
    for (int i = 1; i <= t; i++) {
        cout << (dp[q[i]][0] + dp[q[i]][1]) % MOD << '\n';
    }
    return 0;
}