#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main() {
	
	int N;
	cin>>N;

	vector<int> arr(N);
	for(int i = 0; i < N; i++) cin>>arr[i];

	sort(arr.begin(), arr.end());

	int ans = 1;
	int len = 1;

	for(int i = 1; i < N; i++){

		if(arr[i - 1] + 1 == arr[i]) len++;
		else len = 1;

		ans = (len + 0LL + ans) % mod;

	}

	cout<<ans<<endl;
	
}
