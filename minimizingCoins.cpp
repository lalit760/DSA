#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int x,vector<int>&c, vector<int>&dp){
    if(x < 0) return INT_MAX;
    if(x==0) return 0;
    
    if(dp[x] != -1) return dp[x];

    dp[x] = INT_MAX;

    for(auto coin : c){
        if(x >= coin){
            int temp = solve(x-coin, c, dp);
            if(temp != INT_MAX){
                dp[x] = min(dp[x], 1 + temp);
            }
        }
    }
    return dp[x];

}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>c(n,0);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    vector<int>dp(x+1, -1);
    // for(auto coin : c){
    //     if(coin <= x) dp[coin] = 1;
    // }
    int ans = solve(x,c, dp);
    
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
}