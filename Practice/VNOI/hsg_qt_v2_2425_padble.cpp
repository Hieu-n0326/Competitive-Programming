#include <bits/stdc++.h>        
using namespace std;

long long p[200005], has[200005];
long long n, mod = 1e9 + 7, base = 31;
string s;

void pre () {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i-1] * base) % mod;
    }
    has[0] = 0;
    for (int i = 1; i <= n; i++) {
        has[i] = (has[i-1] * base + (s[i] - 'a' + 1)) % mod;
    }
}

long long get (long long l, long long r) {
    return (has[r] - (has[l-1] * p[r-l+1]) % mod + mod) % mod;
}

bool palin (long long l, long long r) {
    long long mid = (l + r) / 2;
    return get (l, mid) == get (mid+1, r);
}

bool palin2 (long long l, long long r) {
    long long mid = (l + r + 1) / 2;
    for (int i = l; i <= mid; i++) {
        if (s[i] != s[r - (i - l) + 1]) return 0;
    }
    return 1;
}

bool check (long long k) {
    for (int i = 1; i + k - 1 <= n; i++) {
        long long c = i + k - 1;
        long long mid = (i + c) / 2;
        if (palin2 (i, mid) && palin2 (mid + 1, c)) {
            return true;
        }
    }
    return false;
}

long long bs (long long l, long long r) {
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (mid % 2 == 1) mid--;
        if (check(mid)) {
            l = mid + 2;
        }
        else {
            r = mid - 2;
        }
    }
    return r;
}

int main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    cin >> s;
    n = s.size();
    s = " " + s;
    pre ();
    long long res = bs (4, n);
    cout << res << "\n";
    long long cnt = 0;
    for (int i = 1; i + res - 1 <= n; i++) {
        long long c = i + res - 1;
        long long mid = (i + c) / 2;
        if (palin2 (i, mid) && palin2 (mid + 1, c)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}