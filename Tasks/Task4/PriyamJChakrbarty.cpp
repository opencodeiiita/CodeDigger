#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define pb push_back

set<pair<int, int>> friends;
int n;
ll dp[1 << 20]; 

ll solve(int mask) {
    if (mask == 0) return 1;
    if (dp[mask] != -1) return dp[mask];

    ll count = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (mask & (1 << i)) { 
            for (int j = i + 1; j < 2 * n; j++) {
                if ((mask & (1 << j)) && friends.find({i + 1, j + 1}) != friends.end()) {
                    // Pair i+1 and j+1
                    int newMask = mask ^ (1 << i) ^ (1 << j); 
                    count %= MOD;
                }
            }
            break; 
        }
    }

    return dp[mask] = count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;

    if (m < n) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends.insert({a, b});
        friends.insert({b, a}); 
    }

    memset(dp, -1, sizeof(dp));
    int fullMask = (1 << (2 * n)) - 1; 
    cout << solve(fullMask) << endl;

    return 0;
}
