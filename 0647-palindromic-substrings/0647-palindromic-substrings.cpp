class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int count=0;

        for(int i=0;i<n;i++){
            dp[i][i]=1;
            count++;
        }
        for(int col=1;col<=n;col++){ //upper half
            int i=0; int j=col;
            while(i<n && j<n){
                if(s[i]==s[j] && j-i==1){
                   dp[i][j]=1;
                   count++;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    count++;
                }
                i++; j++;
            }
        }
        return count;
    }
};