#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long n;
    cin >> n;
    map <long long, long long> m;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        m[x]++;
    }
    long long res = 0;
    long long cnt = 0;
    for (auto i : m) {
        if (i.first == 0) continue;
        long long a = i.second;
        res += a * (a - 1) * (a - 2) / 6;
        res += (a * (a - 1) / 2) * cnt;
        cnt += a;
    }
    cout << res << "\n";
}

int main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    long long t;
    cin >> t;
    while (t--) {
        solve ();
    }
    return 0;
}