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

string convert(string a,unordered_map<char,char>b){
    string res="";
    for(auto it:a){res+=b[it];}
    return(res);
}

int main(){
  IOS;
  string s;cin>>s;
  int n;cin>>n;
  vector<string>initial(n);
  unordered_map<char,char>mapping;
  ff(i,0,26){
    mapping[s[i]]=static_cast<char>(i+97);
  }

  ff(i,0,n){
    cin>>initial[i];
  }
  vector<pair<string,int>>final(n);
  ff(i,0,n){
    final[i].first=convert(initial[i],mapping);
    final[i].second=i;
  }
  svec(final);
  for(auto it:final){
    cout<<initial[it.second]<<endl;
  }
  

}
