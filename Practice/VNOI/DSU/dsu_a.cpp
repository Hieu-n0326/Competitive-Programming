#include <bits/stdc++.h>
using namespace std;

const long long N = 3e5 + 5;
long long par[N], sz[N], mx[N], mn[N];

long long find (long long u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

void connect (long long u, long long v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        mx[u] = max(mx[u], mx[v]);
        mn[u] = min(mn[u], mn[v]);
    }
}

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        mx[i] = i;
        mn[i] = i;
    }
    while (m--) {
        string s;
        cin >> s;
        if (s == "get") {
            long long u;
            cin >> u;
            long long x = find(u);
            cout << mn[x] << " " << mx[x] << " " << sz[x] << "\n";
        }
        else {
            long long u, v;
            cin >> u >> v;
            connect(u, v);
        }
    }
}