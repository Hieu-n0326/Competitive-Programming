#include <bits/stdc++.h>
using namespace std;

long long a[1000005];

int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            if (a[i] == a[j]) {
                res += a[i];
                for (int k = i; k <= j; k++) {
                    a[k] -= a[i];
                }
                break;
            }
        }
    }
    cout << res;
    return 0;
}