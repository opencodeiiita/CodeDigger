#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int v, n;
cin>>v>>n;

int arr[n];
 int cir=0, ell=0, para=0;
for( int i=0; i<n; i++){
    cin>>arr[i];
    if(arr[i]==0){
        cir++;
    }
    else if(arr[i]<=v && arr[i]>=0){
        ell++;
    }
    else if(arr[i]>v){
        para++;
    }
}
cout<<cir<<" "<<ell<<" "<<para<<endl;



}
}
