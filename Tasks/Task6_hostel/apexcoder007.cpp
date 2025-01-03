#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define read(v) for(auto &it: v) cin>>it
#define nl "\n"
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define fi first
#define s second
#define mod 1000000007


void solve() {
    ll n;
    cin >> n;
    vl positions(n),time(n);
    for(auto &it: positions) cin >> it;
    for(auto &it: time) cin >> it;
    auto check = [&](vl positions, vl time, double mid)->double {
        ll n = positions.size();
        double leftMax = 0, rightMin = 1e9;
        f(i,0,n){
            if(mid<time[i]) return -1;
            leftMax = max(leftMax, (double)(positions[i]+time[i]-mid));
            rightMin = min(rightMin, (double)(positions[i]-time[i]+mid));
            if(leftMax>rightMin) return -1;
        }
        return (leftMax + rightMin)/2.0;
    };
    double l = 0, r = 1e9, ans = 0;
    while (r - l > 1e-7) { 
        double mid = (l + r) / 2.0;
        double res = check(positions, time, mid);
        if (res != -1) {
            ans = res;
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
