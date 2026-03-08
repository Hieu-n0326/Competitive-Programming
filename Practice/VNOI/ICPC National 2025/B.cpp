#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> a[200005];

bool cmp (pair <long long, long long> x, pair <long long, long long> y) {
    return x.second > y.second;
}

void solve () {
    long long n;
    cin >> n;
    long long cl = 0; 
    for (long long i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        cl = max (cl, a[i].first);
    } 
    sort (a + 1, a + n + 1, cmp);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long c = min (cl, a[i].first);
        long long th = c + a[i].second;
        cout << th << " ";
        res += th * th;
        cl -= c;
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