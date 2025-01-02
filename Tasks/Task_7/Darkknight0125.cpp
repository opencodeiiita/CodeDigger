#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp;

bool cmp(string &a, string &b){

	int p1 = 0, p2 = 0;

	while(p1 < a.length() && p2 < b.length()){
		if(mp[a[p1]] < mp[b[p2]]) return true;
		else if(mp[a[p1]] > mp[b[p2]]) return false;
		p1++;
		p2++;
	}

	return a.length() < b.length();

}

int main() {
	
	int T;
	cin>>T;
	while(T--){

		string order;
		cin>>order;

		int N;
		cin>>N;

		vector<string> words;
		for(int i = 0; i < N; i++){
			string temp;
			cin>>temp;
			words.push_back(temp);
		}

		mp.clear();
		for(int i = 0; i < 26; i++){
			mp[order[i]] = i;
		}

		sort(words.begin(), words.end(), cmp);

		for(auto &s: words) cout<<s<<endl;

	}
	
}
