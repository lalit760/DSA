#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n, unordered_map<int, int> & dp){
    if(n==0) return 0;
    unordered_set<int>digits;
    int num=n;

    if(dp.count(n)) return dp[n];
    dp[n] = INT_MAX;
    
    while(num>0){
        int d = num%10;
        num/=10;

        if(d != 0){
            dp[n] = min(dp[n], 1 + solve(n-d, dp));
        }
    }

    return dp[n];

}

int main(){
    int n; cin>>n;
    unordered_map<int, int>dp;
    cout<<solve(n,dp);
}