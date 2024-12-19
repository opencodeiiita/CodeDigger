#include<bits/stdc++.h>
using namespace std;
int main(){
    
long long int n;
cin>>n;
long long int ans=0;
long long int y=1;
int invalid=0;
while(n>0){
    if((n%10)==8 or (n%10)==9) {cout<<-1;invalid=1;break;}
    
    ans+=(y*(n%10));
    n=n/10;
    y=y*8;


}
if(not invalid) {cout<<ans;}
}
