#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long int
#define pb push_back
#define eb emplace_back
#define db long double
#define f first 
#define s second
#define vi vector<int> 
#define vp vector<pii>
#define vc vector<char>
#define str string
#define vb vector<bool> 
#define vvi vector<vector<int>> 
#define vvs vector<vector<str>>
#define vvb vector<vector<bool>> 
#define vvp vector<vector<pii>>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvvi vector<vector<vector<int>>>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define frs(i,a,b,k) for(int i=a;i<=b;i+=k)
#define frrs(i,a,b,k) for(int i=a;i>=b;i-=k)
#define rs(a,b) resize(a,b)
#define b() begin()
#define e() end()
#define INF 1e18
const int mod=1e9+7;
const int N=10;


int32_t main(){

    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);

    int t=1;
    // cin>>t;

    int n,k;

    while(t--){
        cin>>n>>k;
        vi arr(n+1,0);
        while(k--){
            int l,r;
            cin>>l>>r;
            arr[l]+=1;
            if(r+1<=n) arr[r+1]-=1;
        }

        fr(i,1,n) arr[i]+=arr[i-1];
        sort(arr.b()+1,arr.e());

        if(n&1){
            cout<<arr[(n/2)+1]<<"\n";
        }else{
            cout<<(arr[n/2]+arr[(n/2)+1])/2<<"\n";
        }
    }

   return 0;
}