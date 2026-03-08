#include <bits/stdc++.h>
using namespace std;

long long a[100005];
const long long MOD = 1000000007;
long long dp[100005][105];

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) dp[i][j] = 0;
    }
    for (int j = 1; j <= m; j++) {
        if (a[1] == 0 || a[1] == j) dp[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == 0 || a[i] == j) {
                if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if (j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            else dp[i][j] = 0;
        }
    }
    long long res = 0;
    for (int j = 1; j <= m; j++) {
        res = (res + dp[n][j]) % MOD;
    }
    cout << res;
    return 0;
}