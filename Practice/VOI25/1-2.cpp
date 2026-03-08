#include <bits/stdc++.h>
using namespace std;

long long a[700];

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    if (fopen ("light.inp", "r")) {
        freopen ("light.inp", "r", stdin);
        freopen ("light.out", "w", stdout);
    }
    long long n, q, x, y;
    cin >> n >> q >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        long long l, r;
        cin >> l >> r;
        long long s[3];
        memset (s, 0, sizeof (s));
        long long sum = 0;
        for (int i = l; i <= r; i++) {
            s[a[i]]++;/// go for a long time a long day 
            sum += a[i]; 
        } 
        if (sum % 3 != 0) {
            cout << -1 << "\n";
            continue;
        }
        long long res = 0;
        res += min (s[1], s[2]);
        if (min (s[1], s[2]) == s[1]) {
            res += ((s[2] - s[1]) / 3) * 2;
        } else {
            res += ((s[1] - s[2]) / 3) * 2;
        }
        cout << res << "\n";
    }
    return 0;
}