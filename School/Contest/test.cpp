#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, x, y;
    cin >> n >> x >> y;
    cout << min (x, y) + (n - max (x, y) + 1) - 2 << "\n"; 
}