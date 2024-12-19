#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n ; cin >> n ;
    int v[n];
    for(int i =0 ;i <n;++i){
        cin >> v[i] ;
    }
    int e[n];
    for(int i =0 ;i <n;++i){
        cin >> e[i];
    }

    // precompute edges
    int val[2*n+1];
    int sum =0 ;
    for(int i =0 ;i <n;++i){
        val[i]=sum;
        sum+=e[i];
    }
    for(int i =n ;i <2*n+1;++i){
        val[i]=sum;
        sum+=e[i-n];
    }
    
   
    int q; cin >> q;
    while(q--){
        int l,  r ;
        cin >> l >> r;
        if(l<=r){
            l--;
            r--;
            // 1 is marked at val[n];
            // cout << (l-1+n)%n << " " << (r+n+1)%n << '\n';
            int ini = v[(l-1+n)%n] + v[(r+n+1)%n];
            // cout << ini  << "\n";

            l+=n-1;
            r+=n+1;
            // cout <<"debug of l and r ";
            // cout << l << " " << r << " ";
            // cout << '\n';

            cout << ini + val[n]-( val[r] - val[l]) << '\n';
            // cout << '\n';
            

        }
        else{

            l--;
            r--;
           
            int ini = v[(l-1+n)%n] + v[(r+n+1)%n];
            

            l+=n-1;

            r+=n+1;
            
            if(l>r){
                cout << ini + ( val[l] - val[r]) << '\n';
            // cout << '\n';

            }     
            else{
                cout << 0 << '\n';
            }      
            

            

        }
        

    }
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    t=1;
    // cin >> t ;
    while(t--){
        solve();

    }
    
    return 0;
}
