#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> v(N + 1);
    while (K--) {
        int A, B;
        cin >> A >> B;
        v[A]++;
        v[B]--;
    }
    for (int i = 1; i <= N; i++) {
        v[i] += v[i - 1];
    }  
    sort(v.begin(), v.end());
    cout << v[(N + 1) / 2];
}

signed main() {
    solve();  
    return 0;
}
