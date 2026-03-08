#include <bits/stdc++.h>
using namespace std;

const long long N = 1000005, M = 1005;
long long n;
long long a[M][M];

void snt () {
    long long p[N];
    for (int i = 0; i <= 100000; i++) p[i] = 1;
    p[0] = p[1] = 0;
    for (int i = 2; i <= 100000; i++) {
        for (int j = i*i; j <= 100000; j++) p[j] = 0;
    }
}

void prefix () {
    long long p[M][M];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
        }
    }
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1];
}

void rmq () {
    long long st[20][N], lg[N];
    void build () {
        lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        for (int i = 1; i <= n; i++) st[0][i] = a[i];
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }
    void query (long long l, long long r) {
        long long k = lg[r-l+1];
        cout << min (st[k][l], st[k][r - (1 << k) + 1]);
    }
}

void bit () {
    long long bit[N];
    void update (long long i, long long x) {
        while (i <= n) {
            bit[i] += x;
            i += i & (-i);
        }
    }
    long long query (long long i) {
        long long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }
}

void segtree() {
    long long st[4*N];
    void build (long long id, long long l, long long r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        long long mid = (l + r) / 2;
        build (id*2, l, mid);
        build (id*2+1, mid+1, r);
        st[id] = st[id*2] + st[id*2+1];
    }   
    void update (long long id, long long l, long long r, long long pos, long long val) {
        if (l == r) {
            st[id] = val;
            return;
        }
        long long mid = (l + r) / 2;
        if (pos <= mid) update (id*2, l, mid, pos, val);
        else update (id*2+1, mid+1, r, pos, val);
        st[id] = st[id*2] + st[id*2+1];
    }
    void query (long long id, long long l, long long r, long long ql, long long qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return st[id];
        long long mid = (l + r) / 2;
        return query (id*2, l, mid, ql, qr) + query (id*2+1, mid+1, r, ql, qr);
    }
}

void dsu () {
    long long par[N], sz[N];
    void init () {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    long long find (long long u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    void merge (long long u, long long v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

void knapstack () {
    long long dp[N];
    void solve (vector<long long> &w, vector<long long> &v, long long W) {
        for (int i = 0; i <= W; i++) dp[i] = 0;
        for (int i = 0; i < w.size(); i++) {
            for (int j = W; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[W];
    }
}

void dfs () {
    long long m;
    vector <long long> g[N];
    bool visited[N];
    void dfs (long long u) {
        visited[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            long long v = g[u][i];
            if (!visited[v]) dfs(v);
        }
    }
}

void bfs () {
    long long m;
    vector <long long> g[N];
    queue <long long> q;
    bool visited[N];
    void bfs (long long s) {
        q.push(s);
        visited[s] = true;
        while (!q.empty()) {
            long long u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); i++) {
                long long v = g[u][i];
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void dijkmin () {
    long long m;
    vector <pair<long long, long long>> g[N];
    priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    long long dist[N];
    void dijkstra () {
        for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty()) {
            long long u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if (d > dist[u]) continue;
            for (int i = 0; i < g[u].size(); i++) {
                long long v = g[u][i].first;
                long long w = g[u][i].second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}
