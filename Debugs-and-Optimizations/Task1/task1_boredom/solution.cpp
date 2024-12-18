#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
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

// Functions for taking input and printing arrays, vectors, and sets
void takeA(int a[], int n) { for(int i=0; i<n; i++) cin >> a[i]; }
void printA(int a[], int n) { for(int i=0; i<n; i++) cout << a[i] << " "; cout << endl; }
void takeB(vector<int> &a, int n) { for(int i=0; i<n; i++) cin >> a[i]; }
void printB(const vector<int> &a) { for(auto i : a) cout << i << " "; cout << endl; }
void takeA(set<int> &a, int n) { for(int i=0; i<n; i++) { int k; cin >> k; a.insert(k); } }
void printA(const set<int> &a) { for(auto i : a) cout << i << " "; cout << endl; }

const int N = 1e6 + 7;

const int M = 1e9 + 7;
const int MX = sqrt(N) + 5;
const long long MAXN = 2e6;
const long long MOD = 1e9 + 7;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

vector<bool> isprime(MX, 1);
vector<int> primes;

void sieve(){
    for(int i = 2; i < MX; i++) {
        for(int j = 2; i * j < MX; j++) {
            isprime[i * j] = 0;
        }
    }
    for(int i = 2; i < MX; i++) {
        if(isprime[i]) primes.push_back(i);
    }
}

vector<int> minDiv(MAXN);

void sieve_of_Era(){
    for (int i = 2; i < MAXN; ++i) {
        if (minDiv[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                if (minDiv[j] == 0) {
                    minDiv[j] = i;
                }
            }
        }
    }
}


int binexp(int a, int b, int m){
    int result = 1;
    while(b > 0){
        if(b & 1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

int divMod(ll a, ll b, int m){
    return ((a % m) * (binexp(b, m-2, m)) % m) % m;
}

long long exp(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (long long i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

long long choose(long long n, long long r) { 
    if(r>n)return 0ll;
    return (fac[n] * inv[r] % MOD * inv[n - r] % MOD)%MOD;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

vector<tuple<int, int, int, int>> sex(N);
vector<int> h, d;

tuple<int, int, int, int> op(tuple<int, int, int, int> a, tuple<int, int, int, int> b, int dist) {
    int sum_a = get<0>(a), pmax_a = get<1>(a), pmin_a = get<2>(a), ans_a = get<3>(a);
    int sum_b = get<0>(b), pmax_b = get<1>(b), pmin_b = get<2>(b), ans_b = get<3>(b);

    int amax = max(pmax_a, sum_a + pmax_b + dist);
    int amin = min(pmin_a, sum_a + pmin_b + dist);
    int ans = max({ans_a, ans_b, pmax_b + sum_a - pmin_a + dist});

    return make_tuple(sum_a + sum_b + dist, amax, amin, ans);
}

void build(vector<int>& d, vector<int>& h, int v, int tl, int tr) {
    if(tl == tr) {
        sex[v] = make_tuple(0, h[tl], -h[tl], INT_MIN);
    } else {
        int tm = (tl + tr) / 2;
        build(d, h, 2*v, tl, tm);
        build(d, h, 2*v+1, tm + 1, tr);
        sex[v] = op(sex[2*v], sex[2*v+1], d[tm]);
    }
}

tuple<int, int, int, int> query(int v, int tl, int tr, int l, int r) {
    if(l > r) return make_tuple(0, 0, INT_MAX, INT_MIN);
    if(tl == l && tr == r) {
        return sex[v];
    }

    int tm = (tl + tr) / 2;

    if(r <= tm) {
        return query(2*v, tl, tm, l, min(r, tm));
    } else if (l >= tm + 1) {
        return query(2*v+1, tm+1, tr, max(tm+1, l), r);
    } else {
        return op(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm + 1, tr, max(tm+1, l), r), d[tm]);
    }
}

void solve() {
    int n;
    cin >> n;
    d.assign(2*n, 0);
    h.assign(2*n, 0);
    for(int i=0; i<n; i++) cin >> h[i + 1];
    for(int i=0; i<n; i++) cin >> d[i + 1];

    for(int i=1; i<n; i++) {
        d[n+i] = d[i];
        h[n+i] = h[i];
    }

    build(d, h, 1, 1, 2*n-1);
    
    int q; cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        if(l <= r) {
            int l1 = r+1, r1 = l+n-1;
            auto val1 = query(1, 1, 2*n-1, l1, r1);
            cout << get<3>(val1) << endl;
        } else {
            int l1 = r+n+1, r1 = l+n-1;
            auto val1 = query(1, 1, 2*n-1, l1, r1);
            cout << get<3>(val1) << endl;
        }
    }
}

signed main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
