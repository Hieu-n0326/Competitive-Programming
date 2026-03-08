#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
long long dp[1005][1005];
const long long MOD = 1000000007;

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i][1] == '*') break;
        dp[i][1] = 1; 
    }
    for (int i = 1; i <= n; i++) {
        if (a[1][i] == '*') break;
        dp[1][i] = 1; 
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (a[i][j] == '*') {
                continue;
            }
            if (a[i-1][j] != '*') dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (a[i][j-1] != '*') dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n][n];
    return 0;
}