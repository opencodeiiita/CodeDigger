#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
  int n,k;
  cin>>n>>k;
  vector <int> v(n,0);
  for (int i=0; i<k; i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    for (int j=a; j<=b; j++){
      v[j]++;
    }
  }
  sort(v.begin(), v.end());
  cout<<v[((n-1)/2)]<<endl;
}
