#include <bits/stc++.h>
using namespace std;
#define int long long

#define fastio         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);



int med(int n, int k, vector<pair<int, int>>& ins) {
    vector<int> d(n + 2, 0);
    

    for (auto& p : ins) {
        int a = p.first, b = p.second;
        d[a]++;
        if (b + 1 <= n) d[b + 1]--;
    }
    
    
    vector<int> h(n + 1, 0);
    int ch = 0; 
    for (int i = 1; i <= n; ++i) {
        ch += d[i];
        h[i] = ch;
    }
    
    int m_pos = (n + 1) / 2; 
    int max_h = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > max_h) max_h = h[i];
    }
    
    vector<int> cnt(max_h + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cnt[h[i]]++;
    }
    
    int cc = 0;  
    for (int i = 0; i <= max_h; ++i) {
        cc += cnt[i];
        if (cc >= m_pos) return i;
    }
    return 0;  
}

signed main() {
    
    fastio;
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ins(k);
    for (int i = 0; i < k; ++i) {
        cin >> ins[i].first >> ins[i].second;
    }
    cout << med(n, k, ins) << endl;
    return 0;
}
