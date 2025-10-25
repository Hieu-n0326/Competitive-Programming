#include <bits/stdc++.h>
using namespace std;

long long d[30];
long long sl, n;
long long dp[30][2][2][2][2];

long long f (long long pos, bool tight, bool st, bool one, bool cor) {
    if (pos == sl+1) {
        return (st && cor) ? 1 : 0;
    }
    if (dp[pos][tight][st][one][cor] != -1) {
        return dp[pos][tight][st][one][cor];
    }
    long long cnt;
    cnt = 0;
    long long lim = tight ? 9 : d[pos];
    for (long long i = 0; i <= lim; i++) {
        long long nt = tight || (i < d[pos]);
        long long nst = st || (i != 0);
        long long none = 0;
        long long ncor = cor;
        if (nst) {
            if (i == 4) ncor = 1;
            if (one && i == 3) ncor = 1;
            none = (i == 1);
        } else {
            none = 0;
        }
        cnt += f(pos+1, nt, nst, none, ncor);
    }
    return dp[pos][tight][st][one][cor] = cnt;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sl = 0;
    while (n) {
        sl++;
        long long tmp = n % 10;
        d[sl] = tmp;
        n /= 10;
    }
    reverse(d+1, d+sl+1);
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0, 0, 0, 0);
    return 0;
}