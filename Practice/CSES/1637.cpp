#include <bits/stdc++.h>
using namespace std;

long long dp[1000006];

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for (int i = 0; i <= n; i++) dp[i] = 1e9;
    for (int i = 0; i <= 9; i++) dp[i] = 1;
    for (int i = 10; i <= n; i++) {
        string c = to_string(i);
        for (int j = 0; j < c.size(); j++) {
            dp[i] = min(dp[i], dp[i - (c[j] - '0')] + 1);
        }
    }
    cout << dp[n];
    return 0;
}