#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    const int MOD = 1000000000+7;
    vector<long long>dp(n+1,0);

    dp[0]=1;
    for(int i=1;i<=n;i++){ // traveling till number n
        for(int dice=1;dice<=6;dice++){ //for all dice outcome
            if(i-dice >= 0){
                dp[i] = (dp[i] + dp[i-dice])%MOD;
            }
        }
    }  
    // int ans = dp[n];
    cout<<dp[n];
    
}