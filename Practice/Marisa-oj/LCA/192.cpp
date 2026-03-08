#include <bits/stdc++.h>
using namespace std;

const long long lg = 21, N = 200005; 
long long par[N], up[N][lg], h[N], l[N], kc[N];
long long n;
vector <pair <long long, long long>> g[N];

void logg () {
    l[1] = 0;
    for (int i = 2; i <= n; i++) {
        l[i] = l[i / 2] + 1;
    }
}

void dfs (int u) {
    for (int v = 0; v < g[u].size(); v++) {
        long long gt = g[u][v].first;
        if (gt == up[u][0]) continue;
        h[gt] = h[u] + 1;
        kc[gt] = kc[u] + g[u][v].second;
        up[gt][0] = u;
        for (int j = 1; j < lg; j++) {
            up[gt][j] = up[up[gt][j - 1]][j - 1];
        }
        dfs(gt);
    }
}

long long lca (long long u, long long v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap (u, v);
        long long k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; j++) {
            if (k >> j & 1) {
                u = up[u][j];
            }
        }
    }
    if (u == v) return u;
    long long k = l[h[u]];
    for (int j = k; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

long long dist (long long u, long long v) {
    long long p = lca (u, v);
    return kc[u] + kc[v] - 2 * kc[p];
}
int main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    logg ();
    cin >> n;
    long long q;
    cin >> q;
    for (int i = 1; i < n; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back ({v, w});
        g[v].push_back ({u, w});
    }
    h[1] = 0;
    dfs (1);
    while (q--) {
        long long u, v;
        cin >> u >> v;
        cout << dist (u, v) << "\n";
    }
    return 0;
}