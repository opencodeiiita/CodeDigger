#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz(x) ((long long)(x).size())
#define vl vector<ll>

int n, k;

bool check(ll m,vl &a,vl &dp,vl &b) {
    for(ll i=0;i<n;i++){
        if(a[i]>=m){
            b[i]=1;
        } 
        else{
            b[i]=-1;
        }
    }

    dp[0] = b[0];
    for(ll i=1;i<n;i++){
        if(i%k==0){
            dp[i]=max(dp[i-k],b[i]);
        } 
        else{
            dp[i]=dp[i-1]+b[i];
            if(i>k){
                dp[i]=max(dp[i],dp[i-k]);
            }
        }
    }
    return dp[n-1] > 0;
}


void solve()
{
    cin>>n>>k;
    vl a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    vl dp(n,0),b(n,0);
    ll l=1,r=1e9;
    while(l<=r){
        ll m =(l+r)/2;
        if(check(m,a,dp,b)){
            l=m+1;
        } 
        else{
            r=m-1;
        }
    }
    cout<<r<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int T=1;
    // cin>>T;
    while(T--)
        solve();

    return 0;
}
