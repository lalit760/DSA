class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        queue<pair<int,int>>q;
        
        q.push({knightPos[0],knightPos[1]});
        
        vector<vector<int>>dist(n+1,vector<int>(n+1,-1));
        
        dist[q.front().first][q.front().second] = 0;
        if(knightPos == targetPos) return 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int d=0;d<8;d++){
                int nr = i + dir[d][0];
                int nc = j + dir[d][1];
                if(nr<1 || nr>n || nc<1 || nc>n) continue;
                if(dist[nr][nc] != -1) continue;
                
                dist[nr][nc] = dist[i][j] + 1;
                if(nr==targetPos[0] && nc==targetPos[1]){
                    return dist[nr][nc];
                
                }
                
                q.push({nr,nc});
            }
        }
        return -1;
    }
};