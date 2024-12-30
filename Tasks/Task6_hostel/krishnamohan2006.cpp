/*


 .----------------.  .----------------. 
| .--------------. || .--------------. |
| |  ___  ____   | || | ____    ____ | |
| | |_  ||_  _|  | || ||_   \  /   _|| |
| |   | |_/ /    | || |  |   \/   |  | |
| |   |  __'.    | || |  | |\  /| |  | |
| |  _| |  \ \_  | || | _| |_\/_| |_ | |
| | |____||____| | || ||_____||_____|| |
| |              | || |              | |
| '--------------' || '--------------' |
 '----------------'  '----------------' 


*/


#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;


//Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define km cout.tie(NULL);

//Aliases
using ll= long long;
using lld= long double;
using ull= unsigned long long;

//Constants
const lld pi= 3.141592653589793238;
const ll mod=1e9+7;

//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define all(v) v.begin(),v.end()
#define rall(v) v.end(),v.begin()
#define mini *min_element(v.begin(), v.end())
#define maxi *max_element(v.begin(), v.end())
#define summ accumulate(v.begin(), v.end(), 0)
#define rev reverse(v.begin(), v.end())
#define getSet(x) __builtin_popcountll(x) 
#define removeDuplicates() v.resize(unique(v.begin(), v.end()) - v.begin());

//Debug
// def
// #define Krishnamohan 1

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}

//Debug
#ifdef Krishnamohan
#define debug(x) cerr << #x<<" "; cerr<<x<<" "; cerr << endl;
#else
#define debug(x);
#endif


//Code by Krishna Mohan
//Language C++
//Practice->Success

//Code

double check(vll &pos, vll &time, double mid) {
    ll n = pos.size();
    double left_max = 0;
    double right_min = 1e9;
    fl(i, n) {
        if (mid < time[i]) {
            return -1;
        }
        //INEQUALITY : (pos[i]-mid+time[i]) <= x <= (pos[i]+mid-time[i])
        left_max = max(left_max, (double)(pos[i] - mid + time[i]));
        right_min = min(right_min, (double)(pos[i] + mid - time[i]));
        if (left_max > right_min) {
            return -1;
        }
    }
    return (left_max + right_min) / 2.0;
}

void solve() {
    ll n;
    cin >> n;
    vll pos(n);
    fl(i, n) cin >> pos[i];
    vll time(n);
    fl(i, n) cin >> time[i];
    double lo = 0, hi = 1e9, ans = 0;
    while (hi - lo > 1e-7) { 
        double mid = (lo + hi) / 2.0;
        double result = check(pos, time, mid);
        if (result != -1) {
            ans = result;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
//Main
int main()
{
    Code By km
    ll t = 1;
    // cin>>t;
    fl(i,t)
    {
        solve();
    }
    // solve();
    // fl(i,t) //Kickstart
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     solve();
    //     cout<<"\n";
    // }
    return 0;
}
//End