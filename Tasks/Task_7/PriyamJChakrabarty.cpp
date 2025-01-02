#include <bits/stdc++.h>
using namespace std;


#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i, a, b) for(int i = (a); i < (b); ++i)

bool cmp(const string &a, const string &b, const unordered_map<char, int> &m) {
    int len = min(a.size(), b.size());
    loop(i, 0, len) {
        if (m.at(a[i]) != m.at(b[i])) 
            return m.at(a[i]) < m.at(b[i]);
    }
    return a.size() < b.size();
}

int main() {
    fastio;
    
    string ord;
    cin >> ord;

    unordered_map<char, int> m;
    loop(i, 0, 26) m[ord[i]] = i;

    int n;
    cin >> n;

    vector<string> v(n);
    loop(i, 0, n) cin >> v[i];

    sort(v.begin(), v.end(), [&m](const string &a, const string &b) {
        return cmp(a, b, m);
    });

    for(const string &s : v) cout << s << '\n';

    return 0;
}
