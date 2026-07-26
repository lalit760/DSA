class Solution {
public:
    vector<vector<int>>dp;
    int helper(string word1, string word2,int i, int j){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j] = helper(word1,word2,i-1,j-1);
        }
        else{
            int x = helper(word1,word2,i,j-1); //inserting something in word1 is equivalent to deleting from word2
            int y = helper(word1,word2,i-1,j); // deteting
            int z = helper(word1,word2,i-1,j-1); //replacing

            return dp[i][j] = 1+min({x,y,z}); //1 operation (just performed) + minimum operations needed for the remaining strings
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();   int n = word2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        int ans = helper(word1,word2, m-1, n-1);
        return ans;
    }
};