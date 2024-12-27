#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int T;
	cin>>T;
	while(T--){

		int N, K;
		cin>>N>>K;

		vector<long long> prefixSum(N + 2, 0);

		for(int i = 0; i < K; i++){
			int l, r;
			cin>>l>>r;
			prefixSum[l]++;
			prefixSum[r + 1]--;
		}

		for(int i = 1; i <= N; i++) prefixSum[i] += prefixSum[i - 1];

		sort(prefixSum.begin(), prefixSum.end());
		cout<<prefixSum[N / 2 + 2]<<endl;

	}
	
}
