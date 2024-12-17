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

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    vector<int> pre(n, 0);
    pre[0] = b[0];
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + b[i];
    }

    int q; cin >> q;
    // cout << a[3] << " " << a[4] << " " << pre[4] << pre[3] <<  endl;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;

        // cout << l << " " << r << endl;

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(i >= l && i <= r) continue;
            for(int j=i+1; j<n; j++){
                if(j >= l && j <= r) continue;
                int ans2 = 0;
                if((i < l && j < l) || (i > r && j > r)){
                    ans2 = pre[j-1] + a[i] + a[j];
                    if(i > 0) ans2 -= pre[i-1];
                } else {
                    ans2 = pre[n-1] - pre[j-1] + a[i] + a[j];
                    if(i > 0) ans2 += pre[i-1];
                }
                ans = max(ans, ans2);
                // cout << i << " " << j << " " << ans << endl;
            }
        }

        cout << ans << endl;
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