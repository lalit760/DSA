class Solution {
public:
    // *** RECURSSION AND MEMOISATION ***
    // vector<vector<int>>dp;
    // int helper(string &t1, string &t2, int i1, int i2){
    //     if(i1<0 || i2<0) return 0;
    //     if(dp[i1][i2] != -1) return dp[i1][i2];
    //     if(t1[i1]==t2[i2]){
    //         return dp[i1][i2] = 1 + helper(t1,t2,i1-1,i2-1); //count means 1+..
    //     }
    //     else{
    //         int p1 = helper(t1,t2,i1-1,i2);
    //         int p2 = helper(t1,t2,i1,i2-1);

    //         return dp[i1][i2] = max(p1,p2);
    //     }
    // }

    int longestCommonSubsequence(string text1, string text2) {
        // int n1 = text1.size();
        // int n2 = text2.size();
        // dp.resize(n1,vector<int>(n2,-1));
        // int ans = helper(text1,text2,n1-1,n2-1);
        // return ans;

        // ** TABULATION **
        int m = text1.size();  int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++){ //marking first column elements = 0
            dp[i][0] = 0;
        }
        for(int i=0;i<=n;i++){ //marking first row elements = 0
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];

                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};