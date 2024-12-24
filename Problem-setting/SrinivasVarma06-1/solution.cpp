#include <bits/stdc++.h>
using namespace std;

long long calculateOperations(vector<int>& chakraLevels, int low, int high) {
    long long operations = 0;
    for (int i=0;i<chakraLevels.size();i++) 
    {
        if (chakraLevels[i]<low) 
            operations += (low-chakraLevels[i]); 
        else if (chakraLevels[i]>high)
            operations += (chakraLevels[i]-high); 
    }
    return operations;
}
int main() {
    int n, k;
    cin>>n>>k;

    vector<int> chakraLevels(n);
    for (int i=0;i<n;i++) 
        cin >> chakraLevels[i];

    int minChakra = *min_element(chakraLevels.begin(), chakraLevels.end());
    int maxChakra = *max_element(chakraLevels.begin(), chakraLevels.end());

    if (maxChakra-minChakra<=k) 
    {
        cout<<0<<endl;
        return 0;
    }

    long long minOperations = LLONG_MAX;

    for (int low=minChakra; low<= maxChakra-k;low++) 
    {
        int high=low+k;
        long long operations = calculateOperations(chakraLevels, low, high);
        minOperations = min(minOperations, operations);
    }

    cout<<(minOperations==LLONG_MAX ? -1:minOperations)<<endl;

    return 0;
}
