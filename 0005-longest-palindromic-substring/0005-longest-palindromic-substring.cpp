class Solution {
public:
    string part(string &str,int s,int e){
        string ans="";
        for(int i=s;i<=e;i++){
            ans.push_back(str[i]);
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        string ans = s.substr(0,1);

        // for(int row=n;row>=0;row--){ //lower half
        //     int i=row; int j=0;
        //     while(i<n && j<n){
        //         if(i==j) dp[i][j]=1;
        //         i++; j++;
        //     }
        // }

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int col=1;col<n;col++){ //upper half
            int i=0; int j=col;
            while(i<n && j<n){
                if(s[i]==s[j] && j-i==1){
                   dp[i][j]=1;
                   if(j-i+1 > ans.size()){
                    ans = part(s,i,j);
                   }
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    if(j-i+1 > ans.size()){
                        ans = part(s,i,j);
                   }
                }
                i++; j++;
            }
        }
        return ans;

    }
};