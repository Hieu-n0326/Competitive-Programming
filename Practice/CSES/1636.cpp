#include <bits/stdc++.h>
using namespace std;
 
int n, x;
int a[105];
int dp[1000005];
const int MOD = 1000000007;
 
int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= x; i++) dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}
 