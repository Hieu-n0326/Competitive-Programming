#include <bits/stdc++.h>
using namespace std;

long long a[200005], b[200005];

void solve () {
    long long n, x;
    cin >> n >> x;
    long long am = 0; 
    long long mid = (n + 1) / 2; 
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) a[i] = x;
        b[i] = a[i];
    }
    sort (b + 1, b + n + 1);
    if (b[mid] == x) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else cout << "NO\n";
    return;
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