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
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}\n"; }
template <class T>
void cin_v(vector<T> &v) { for (auto &x : v) cin >> x;}

#define MOD 1000000007
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

set<pair<int,int>> friends;
int final;
int n;

void rec(vi &v1){
    if(v1.size() == 0){
        final++;
        final%=MOD;
        return;
    }
    f(0, v1.size()-1,i){
        if(friends.find({v1[i],v1[i+1]}) != friends.end()){
            auto v3 = v1;
            v3.erase(v3.begin()+i,v3.begin()+i+2);
            rec(v3);
        }
    }
}

int main() {
    int m;
    cin >> n >> m;

    if(m<n){
        //can never achive it if there are less pairs
        cout << 0 << endl;
        return 0;
    }

    f(0,m,i){
        pair<int,int> a;
        cin >> a.first >> a.second;

        friends.insert(a);
    }

    vi v;
    cf(1,2*n,i) v.push_back(i);

    rec(v);

    cout << final << endl;
    return 0;
}
