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

//solved it using difference array and prefix sums
void solve(){
    ll n,k;
    cin>>n>>k;
    vl v(n,0);
    f(i,0,k){
        ll a,b;
        cin>>a>>b;
        v[a-1]++;           //updating the difference array
        if(b<n) v[b]--;
    }
    f(i,1,n) v[i] = v[i-1] + v[i];   //prefix summing the difference array 
    sort(all(v));          
    cout<<v[n/2]<<nl; 
}

//Time complexity : O(k+nlogn) which is O(nlogn) essentially
//Space complexity : O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
