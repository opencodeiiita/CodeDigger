#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define sin(a,n) for(int i=0;i<n;i++){int temp;cin>>temp;a.insert(temp);}
#define sout(a) for(auto i:a)cout<< i<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(),greater<int>()
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;
#define p(x) cout<<x<<endl;
#define pb push_back
const int M = 1000000007;
const int N = 1e5+10;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		string key;
        cin>>key;
        int n;
        cin>>n;
        vector<string> v(n);
        vin(v)
        map<char,char> mp;
        for(int i=0;i<26;i++){
            mp[key[i]]=char('a'+i);
        }
        map<string,string> mp2;
        for(int i=0;i<n;i++){
            string newstr;
            for(int j=0;j<v[i].size();j++){
                newstr+= mp[v[i][j]];
            }
            mp2[newstr]=v[i];
        }
        for(auto it:mp2){
            cout<<it.second<<endl;
        }
    return 0;
}
