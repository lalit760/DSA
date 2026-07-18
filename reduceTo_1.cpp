// RECURSSION & MEMOIZATION

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int steps(int n, vector<int>&dp){
    if(n==1) return 0;
    // dp[2]=1; dp[3] = 1;

    if(dp[n] != -1){
        return dp[n];
    }

    else if(n%6==0){
        dp[n] = 1 + min(steps(n-1,dp), min(steps(n/2,dp), steps(n/3,dp)));
    }
    else if(n%2==0){
        dp[n] = 1 + min(steps(n-1,dp), steps(n/2,dp));
    }
    else if(n%3==0){
        dp[n] = 1 + min(steps(n-1,dp), steps(n/3,dp));
    }
    else dp[n] = 1 + steps(n-1,dp);

    return dp[n];
}

int main(){
    int n; cin>>n;
    vector<int>dp(n+1, -1);
    cout<<steps(n, dp);
}