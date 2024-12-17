#include <bits/stdc++.h>
using namespace std;

// Shortcuts for common data types and functions
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

#define F first
#define S second
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Debugging macros
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Author
// Written by Ayush

// Function to perform modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function for GCD
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function for LCM
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Solve function
void solve() {
    int n ; cin >> n ;
    int v[n];
    for(int i =0 ;i <n;++i){
        cin >> v[i] ;
    }
    int e[n];
    for(int i =0 ;i <n;++i){
        cin >> e[i];
    }

    // precompute edges
    int val[2*n+1];
    int sum =0 ;
    for(int i =0 ;i <n;++i){
        val[i]=sum;
        sum+=e[i];
    }
    for(int i =n ;i <2*n+1;++i){
        val[i]=sum;
        sum+=e[i-n];
    }

    int q; cin >> q;
    while(q--){
        int l,  r ;
        cin >> l >> r;
        if(l<=r){
            l--;
            r--;
            int ini = v[(l-1+n)%n] + v[(r+n+1)%n];
            l+=n-1;
            r+=n+1;
            cout << ini + val[n]-( val[r] - val[l]) << '\n';
        }
        else{
            l--;
            r--;
            int ini = v[(l-1+n)%n] + v[(r+n+1)%n];
            l+=n+1;
            r+=n-1;
            cout << ini + ( val[r] - val[l]) << '\n';
        }
    }
}

int main() {
    fast_io;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
