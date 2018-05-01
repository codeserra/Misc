#include <bits/stdc++.h>

using namespace std;

/* --------------------------------------------------- 

here we can take addvantage or rearrangment inequality
sort one array in acesnding order other in decending
 the summation will give minimum
 
 
 ** this code is however not working for large data.
 refer testcases in https://www.hackerrank.com/contests/codeeve-3-0/challenges/im-bored/
--------------------------------------------------- */

typedef long long LL;

bigint calculateMinScalar(int k, vector<int> arr1, vector<int> arr2)
{
    //sort arr1 in increarsing order
    sort(arr1.begin(), arr1.end());
    
    //sort arr2 in decrearsing order
    sort(arr2.begin(), arr2.end(), greater<int>());
    
    bigint i_scalar =0; 
    for(int i =0; i<k; i++)
        i_scalar = i_scalar + arr1.at(i)*arr2.at(i);
    
    return i_scalar; 
}

int main() {
    int n;
    cin >> n;
    for (int i =0; i<n; i++)
    {
        int k;
        cin >> k;
        vector<int> arr1(k);
        vector<int> arr2(k);

        for (int ii =0; ii<k; ii++)
            cin>>arr1[ii];

        for (int ii =0; ii<k; ii++)
            cin>>arr2[ii];
        
        bigint sum_i = calculateMinScalar(k, arr1, arr2);
        cout<<"Case #"<<i+1<<": "<< sum_i<<endl;
    }
    return 0;
}
