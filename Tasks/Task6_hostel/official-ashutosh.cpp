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

// Functions for taking input and printing arrays, vectors, and sets
void takeA(int a[], int n) { for(int i=0; i<n; i++) cin >> a[i]; }
void printA(int a[], int n) { for(int i=0; i<n; i++) cout << a[i] << " "; cout << endl; }
void takeB(vector<int> &a, int n) { for(int i=0; i<n; i++) cin >> a[i]; }
void printB(const vector<int> &a) { for(auto i : a) cout << i << " "; cout << endl; }
void takeA(set<int> &a, int n) { for(int i=0; i<n; i++) { int k; cin >> k; a.insert(k); } }
void printA(const set<int> &a) { for(auto i : a) cout << i << " "; cout << endl; }

double check(vector<int> &x, vector<int> &t, int k){
    double l = 0, r = 1e9;
    for(int i=0; i<x.size(); i++){
        int p = k-t[i];
        if(p < 0) return -1;
        l = max(l, (x[i]-p)*1.0);
        r = min(r, (p+x[i])*1.0);
    }

    if(l <= r) return (l+r)/2.0;
    return -1;
}
void solve() {
    int n; cin >> n;
    vector<int> x(n), t(n);
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) cin >> t[i];

    double l = 0, r = 1e9, ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(x, t, mid) != -1){
            ans = check(x, t, mid);
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << fixed << setprecision(6) << ans << endl;
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