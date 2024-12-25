#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define setbits(x)  __builtin_popcountll(x)

const int N = 1010;
const int MOD = 998244353;
int binom[N][N], dp[N][N], check[N][N];

int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return ((a % m) * (b % m)) % m; }

int func(int i, int j) {
    if(j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    for(int k = 0; k < j; k++) {
        if(check[i][i+(2*k) + 1]) {
            int le = func(i+1, k);
            int ri = func(i+(2*k)+2, j-k-1);
            ans = mod_add(ans, mod_mul(mod_mul(le, ri, MOD), binom[j][k+1], MOD), MOD);
        }
    }

    return dp[i][j] = ans;
}

void preBinom() {
    for(int i=0; i<N; i++) {
        binom[i][0] = binom[i][i] = 1;
        for(int j=1; j<i; j++) {
            binom[i][j] = mod_add(binom[i-1][j-1], binom[i-1][j], MOD);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    memset(check, 0, sizeof(check));
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        check[a-1][b-1] = 1;
        check[b-1][a-1] = 1;
    }

    preBinom();
    cout << func(0, n) << endl;
}

signed main() {
    fastio();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
