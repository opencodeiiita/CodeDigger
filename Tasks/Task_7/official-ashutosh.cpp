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
    string s; cin >> s;
    map<char, int> mp;  
    for(int i=0; i<s.length(); i++){
        mp[s[i]] = i;
    }

    int n; cin >> n;
    string t[n];
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    sort(t, t+n, [&](string a, string b){
        int i = 0;
        while(i < a.length() && i < b.length()){
            if(mp[a[i]] != mp[b[i]]){
                return mp[a[i]] < mp[b[i]];
            }
            i++;
        }
        return a.length() < b.length();
    });

    for(int i=0; i<n; i++){
        cout << t[i] << endl;
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