#include <bits/stdc++.h>
using namespace std;

long long a[1005][1005];
long long pre[100005];

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i - 1][j] + a[i]    
        }
    }
}