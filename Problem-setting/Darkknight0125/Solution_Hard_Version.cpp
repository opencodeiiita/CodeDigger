#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main() {
	
	int N;
	cin>>N;

	vector<int> arr(N);
	for(int i = 0; i < N; i++) cin>>arr[i];

	sort(arr.begin(), arr.end());
	
	int cnt = 1;
	vector<pair<int, int>> freq;

	for(int i = 1; i < N; i++){
		if(arr[i - 1] == arr[i]) cnt++;
		else{
			freq.push_back({arr[i - 1], cnt});
			cnt = 1;
		}
	}
	freq.push_back({arr.back(), cnt});

	int ans = freq[0].second;
	long long last = freq[0].second;

	for(int i = 1; i < freq.size(); i++){
		if(freq[i - 1].first + 1 == freq[i].first){
			last = (last * freq[i].second) + freq[i].second;		
		}
		else{
			last = freq[i].second;
		}
		ans = (ans + 0LL + last) % mod;
	}
	
	cout<<ans<<endl;

}
