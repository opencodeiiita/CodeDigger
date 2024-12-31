#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int compare(string s1, string s2, map <char, int> m){
    if (s1.size()>s2.size()){
        return 0;
    }
    else if (s1.size()<s2.size()){
        return 1;
    }
    else{
        for (int i=0; i<s1.size(); i++){
            if (s1[i]==s2[i]){
                continue;
            }
            else{
                if (m[s1[i]]>m[s2[i]]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
        }
    }
}
int32_t main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector <string> v(n);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    map <char, int> m;
    for (int i=1; i<=s.size(); i++){
        m[s[i-1]]=i;
    }
    unordered_set <string> s1;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            int temp=compare(v[i], v[j], m);
            if (!temp){
                swap(v[i],v[j]);
            }
        }
    }
    for (auto it: v){
        cout<<it<<endl;
    }
}
