#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> p(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    int m=0;
    for (int i=0;i<n; i++){
        m=max(m, r[i]);
    }
    int s = -1e18, e = 1e18;

    for (int i = 0; i < n; ++i) {
        s = max(s, p[i] - (m - r[i]));
        e = min(e, p[i] + (m - r[i]));
    }

    double x = (s + e) / 2.0;
    cout << fixed << setprecision(8) << x << endl;

    return 0;
}
