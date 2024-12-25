#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(int N, int M, vector<pair<int, int>> &pairs) {
    int maxMask = 1 << (2 * N); // Total states for bitmask
    vector<int> dp(maxMask, 0);
    dp[0] = 1; // Base case: no one is paired yet

    // Preprocess friendships into an adjacency matrix
    vector<vector<bool>> adj(2 * N, vector<bool>(2 * N, false));
    for (auto &p : pairs) {
        int u = p.first - 1; // Convert to 0-based index
        int v = p.second - 1;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    // Iterate over all masks
    for (int mask = 0; mask < maxMask; ++mask) {
        if (dp[mask] == 0) continue;
        for (int i = 0; i < 2 * N; ++i) {
            if (mask & (1 << i)) continue; // i is already paired
            for (int j = i + 1; j < 2 * N; ++j) {
                if ((mask & (1 << j)) || !adj[i][j]) continue;
                int newMask = mask | (1 << i) | (1 << j);
                dp[newMask] = (dp[newMask] + dp[mask]) % MOD;
            }
        }
    }

    return dp[maxMask - 1]; // Return result for full pairing
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pairs(M);
    for (int i = 0; i < M; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    cout << countWays(N, M, pairs) << endl;
    return 0;
}
