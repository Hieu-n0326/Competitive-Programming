#include <bits/stdc++.h>
using namespace std;

const long long N = 1000005;
long long dp[N][4], a[N], b[N], c[N];

int main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);

    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];



}