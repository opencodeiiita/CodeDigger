#include<bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define ll long long
#define pb push_back
#define ff(i,s,e) for(int i=s;i<e;i++)
#define fb(i,e,s) for(int i=e;i>s;i--)
#define svec(x) sort(x.begin(),x.end())
#define mod 1000000007
#define maxvec(x) *max_element(x.begin(),x.end())
#define minvec(x) *min_element(x.begin(),x.end())
#define mset(v,m) memset(v,m,sizeof(m))

int main(){
  IOS;
  int n;int k;
  cin>>n>>k;
  vector<pair<int,int>>v;
  ff(i,0,k){
    int a;int b;
    cin>>a>>b;
    v.pb(make_pair(a,b));

  }
  vector<int>h(n,0);
  for (auto it:v){
    h[it.first-1]+=1;
    if(it.second!=n) h[it.second]-=1;
    

  }
  vector<int>pf(n);
  int s=0;
  ff(i,0,n){
    s+=h[i];
    pf[i]=s;
  }
  svec(pf);
  cout<<pf[n/2];

}

