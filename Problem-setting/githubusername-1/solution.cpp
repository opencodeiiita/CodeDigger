#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
  int n,x;
  cin>>n>>x;
  int ans=0;
  ans+=min(x-1,n-x);
  ans+=(ceil(n*1.0/2)-ans-1)*2;
  cout<<ans<<endl;
 }
    
signed main(){ 
  ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
     int t;
     cin>>t;
    while(t--){
   solve();
     }
return 0;
}
