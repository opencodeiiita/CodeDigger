#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int T;
	cin>>T;
	while(T--){

		int N, X;
		cin>>N>>X;

		vector<int> arr(N);
		for(int i = 0; i < N; i++) cin>>arr[i];

		vector<int> temp = arr;
		sort(temp.begin(), temp.end());

		int left = N - X, right = X - 1;

		bool isPossible = true;

		for(int i = left; i <= right; i++){
			if(arr[i] != temp[i]){
				isPossible = false;
				break;
			}
		}

		cout<<((isPossible) ? "YES" : "NO")<<endl;

	}
	
}
