#include <bits/stdc++.h>
using namespace std;

long long dp[100005];
long long h[1005], s[1005];

int main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    long long n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= x; i++) {
        dp[i] = 0;  
    }
    for (int i = 2; i <= n + 1; i++) {
        for (int j = x; j >= h[i - 1]; j--) {
            dp[j] = max (dp[j], dp[j - h[i - 1]] + s[i-1]);
        }
    }
    long long mx = 0;
    for (int i = 0; i <= x; i++) {
        mx = max (mx, dp[i]);
    }
    cout << mx;
    return 0;
}