#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int T;
	cin>>T;
	while(T--){

		int n, k;
		cin>>n>>k;

		vector<long> pf(n+ 2, 0);

		for(int i = 0; i < k; i++){
			int l, r;
			cin>>l>>r;
			pf[l]++;
			pf[r + 1]--;
		}

		for(int i = 1; i <= n; i++)
        {
            pf[i] += pf[i - 1];
        } 

		sort(pf.begin(), pf.end());
		cout<<pf[n / 2 + 2]<<endl;

	}
	
}
