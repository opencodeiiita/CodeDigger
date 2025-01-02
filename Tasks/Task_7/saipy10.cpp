#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<char, int> mpp;
bool compare(string &a, string &b){

	int p1 = 0, p2 = 0;

	while(p1 < a.length() && p2 < b.length()){
		if(mpp[a[p1]] < mpp[b[p2]]) return true;
		else if(mpp[a[p1]] > mpp[b[p2]]) return false;
		p1++;
		p2++;
	}

	return a.length() < b.length();

}

int main() {

	int T;
	cin>>T;
	while(T--){
		mpp.clear();

		string lexorder;
		cin>>lexorder;

		int N;
		cin>>N;

		vector<string> letters;
		for(int i = 0; i < N; i++){
			string ele;
			cin>>ele;
			letters.push_back(ele);
		}

		for(int i = 0; i < 26; i++){
			mpp[lexorder[i]] = i;
		}

		sort(letters.begin(), letters.end(), compare);

		for(auto &s: letters) cout<<s<<endl;

	}

}