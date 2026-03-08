#include <bits/stdc++.h>
using namespace std;

long long a[700];

char phai (char c) {
    if (c =='2') return '0';
    else return c + 1;
}

char trai (char c) {
    if (c =='0') return '2';
    else return c - 1;
}
map<string, bool> vis;

void bfs (long long l, long long r) {
    string res;
    string s;
    for (int i = l; i <= r; i++) {
        s += to_string(a[i]);
    }
    long long k = s.size();
    s = " " + s;
    for (int i = 1; i <= k; i++) {
        res += '0';
    }
    res = " " + res;
    queue <pair <string, long long>> q;
    q.push ({s, 0});
    vis.clear();
    vis[s] = 1;
    while (!q.empty()) {
        string cur = q.front().first; 
        long long t = q.front().second;
        q.pop();
        if (cur == res) {
            cout << t << "\n";
            return;
        }
        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= k; j++) {
                if (cur[i] == '0' && cur[j] == '0') continue;
                string nx = cur;
                nx[i] = phai (nx[i]);
                nx[j] = trai (nx[j]);
                if (!vis[nx]) {
                    vis[nx] = 1;
                    q.push ({nx, t + 1});
                }
                nx = cur;
                nx[i] = trai (nx[i]);
                nx[j] = phai (nx[j]);
                if (!vis[nx]) {
                    vis[nx] = 1;
                    q.push ({nx, t + 1});
                }
            }
        }
    }
    cout << -1 << "\n";
}

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
        bfs (l, r);
    }
    return 0;
}