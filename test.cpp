#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long res[200005];

void back (long long step, long long pos) {
    if (pos > n) {
        return;
    }
    for (int i = 1; i <= n/k; i++) {
        long long nx = pos + (k + step) * i;
        if (nx <= n) {
            res[nx]++;
            back(step, nx);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    back(0, 0);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}