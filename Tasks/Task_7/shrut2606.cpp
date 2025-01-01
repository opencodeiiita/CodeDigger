#include <bits/stdc++.h>
using namespace std;

string compare(string x,string y,int a[]){
    for(int i=0;i<min(x.length(),y.length());i++){
        if(a[x[i]-'a']>a[y[i]-'a'])
            return x;
        else if(a[x[i]-'a']<a[y[i]-'a'])
            return y;
    }
    if(x.length()<y.length())
    return y;
    else 
    return x;
}

int main(){
    string s;
    cin >> s;
    int a[26];
    for(int i=0;i<26;i++){
        a[s[i]-'a']=i;
    }
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    
    for(int i=n-1;i>=0;i--){
        int b=i;
        string big=str[i];
        for(int j=0;j<i;j++){
            // cout<<str[j]<<" "<<big<<" "<<compare(str[j],big,a)<<endl;
            if(compare(str[j],big,a)==str[j]){
                b=j;
                big=str[j];
            }
        }
        string temp=str[i];
        str[i]=big;
        str[b]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
}