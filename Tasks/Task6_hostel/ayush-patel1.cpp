#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) (v).begin(), (v).end()
#define F(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define sz(x) (ll)(x).size()

ld mxT(const vector<ll>& p, const vector<ll>& t, ld x) {
    ld mx = 0;
    F(i, 0, sz(p)) {
        mx = max(mx, t[i] + abs(x - p[i]));
    }
    return mx;
}

ld findX(const vector<ll>& p, const vector<ll>& t) {
    ld l = *min_element(all(p)), r = *max_element(all(p)), eps = 1e-7;
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3.0, m2 = r - (r - l) / 3.0;
        if (mxT(p, t, m1) < mxT(p, t, m2)) r = m2;
        else l = m1;
    }
    return (l + r) / 2.0;
}

int main() {
    fastio
    ll n;
    cin >> n;
    vector<ll> p(n), t(n);
    F(i, 0, n) cin >> p[i];
    F(i, 0, n) cin >> t[i];
    cout << fixed << setprecision(6) << findX(p, t) << endl;
}
