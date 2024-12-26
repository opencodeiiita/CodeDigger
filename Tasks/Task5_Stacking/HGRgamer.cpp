#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>

#define f(s,e,i) for(long long int i=s;i<e;i++)
#define cf(s,e,i) for(long long int i=s;i<=e;i++)
#define rf(s,e,i) for(long long int i=s;i>=e;i--)
#define pb push_back

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void cin_v(vector<T> &v) { for (auto &x : v) cin >> x;}

#define MOD 1000000007
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


int main() {
    int n,k;
    cin >> n >> k;

    vi v(n,0);

    f(0,k,i){
        int a,b;
        cin>>a>>b;
        f(a-1,b,j){
            v[j]++;
        }
    }
    sort(all(v));
    cout << v[n/2] << endl;

    return 0;
}
