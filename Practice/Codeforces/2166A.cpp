#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long n;
    string s;
    cin >> n >> s;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n-1]) res++;
    }
    cout << res << "\n";
    return;
}

int main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}