#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=0;

    while(k--){
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }
    for(int i=1;i<=n;i++)
        arr[i]=arr[i-1]+arr[i];
    
    sort(arr,arr+n+1);
    cout<<arr[(n+1)/2];                   //kyuki I added 0 in the beginning 
}