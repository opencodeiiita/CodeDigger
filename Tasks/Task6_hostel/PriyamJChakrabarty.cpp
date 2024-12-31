#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ld mxTime(const vector<int>& pos, const vector<int>& t, ld x) {
    ld mx = 0;
    for (size_t i = 0; i < pos.size(); ++i) {
        mx = max(mx, t[i] + abs(x - pos[i]));
    }
    return mx;
}

ld findX(const vector<int>& pos, const vector<int>& t) {
    ld l = *min_element(pos.begin(), pos.end());
    ld r = *max_element(pos.begin(), pos.end());
    const ld eps = 1e-7;

    while (r - l > eps) {
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;

        ld tm1 = mxTime(pos, t, m1);
        ld tm2 = mxTime(pos, t, m2);

        if (tm1 < tm2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    return (l + r) / 2.0;
}

signed main() {
    fastio
    int n;
    cin >> n;

    vector<int> pos(n), t(n);

    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    cout << fixed << setprecision(6) << findX(pos, t) << endl;

    return 0;
}
