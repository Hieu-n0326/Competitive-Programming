#include <bits/stdc++.h>
using namespace std;

long long v[3];

long long gt (char c) {
    if (c == 'G') return v[0];
    if (c == 'W') return v[1];
    if (c == 'R') return v[2];
}

char next (char c) {
    if (c == 'G') return 'W';
    if (c == 'W') return 'R';
    if (c == 'R') return 'G';
}
void solve () {
    long long g, w, r, t;
    cin >> g >> w >> r >> t;
    v[0] = g;
    v[1] = w;
    v[2] = r;
    char cur = 'G';
    long long cnt = 1, sum = 0;
    for (int i = 0; i < t; i++) {
        cnt++;
        if (cnt > gt(cur)) {
            cur = next(cur);
            cnt = 1;
        }
    }
    if (cur == 'G') cout << "Guiding Beat";
    else if (cur == 'W') cout << "Warning Beat";
    else cout << "Resting Phase";
    cout << "\n";
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