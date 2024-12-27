#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],t[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>t[i];

    if (n==1)
        cout<< a[0];
    else{
        double low=a[0],high=a[n-1];
        while((high-low)>=1e-7){
            double mid=(high+low)/2;
            double big=0;
            int pos=0;
            for(int i=0;i<n;i++){
                double temp=t[i]+abs(mid-a[i]);
                if(temp>big){
                    big=temp;
                    pos=i;
                }
            }
                if(a[pos]>mid)
                low=mid;
                else
                high=mid;
            
        }cout<<low;
    }
}