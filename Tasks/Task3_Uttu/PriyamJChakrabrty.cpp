#include <bits/stdc++.h>     
using namespace std;
 
#define int long long
#define fastio         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \ 
    cout.tie(NULL);


void solve()
{
    int n, x, a;

    cin>> n>>x;

    vector<int> v;

    vector<int> v2;

    for(int i = 0; i< n; i++)
    {
        cin >> a;
        v.push_back(a);
        v2.push_back(a);
    }

    sort(v.begin(),v.end());

    if(n>=2*x){cout<<"YES"<<endl;return;}

    for (int i = n-x ; i<x ; i++)
    {
        if (v[i]!=v2[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout<<"YES"<<endl;

    return;

}
 
signed main()
{
   
fastio;
    
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}