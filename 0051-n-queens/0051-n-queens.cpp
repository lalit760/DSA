class Solution {
public:
    vector<vector<char>>grid;
    vector<vector<string>>ans;
    bool canPlace(int row, int col,int n){ // finding the safe spots
        //column check
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q'){ //we are attacked
                return false;
            }   
        }
        //left-up diag check
        for(int i=row-1,j=col-1 ;i>=0 && j>=0 ;i--,j--){
            if(grid[i][j]=='Q')return false;
        }
        //right-up diag check
        for(int i=row-1,j=col+1 ;i>=0 && j<n ;i--,j++){
            if(grid[i][j]=='Q')return false;
        }
        return true;
    }

    void f(int row,int n){
        if(n==row){ //we got possible ans
            
            vector<string>v; //making a vector of string like "...Q"
            for(int i=0;i<n;i++){
                string s="";   // making that string
                for(int j=0;j<n;j++){
                    s+= grid[i][j];
                }
                v.push_back(s);
            }
            ans.push_back(v);  // pushing that vector of string into the 2d vector
            return ;
        }

        for(int col=0;col<n;col++){
            if(canPlace(row,col,n)){
                grid[row][col] = 'Q'; //doing some changes
                f(row+1,n);         // recurssive call
                grid[row][col] = '.';   // revert the changes
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        
        grid.resize(n, vector<char>(n,'.'));
        // ans.clear();
        f(0,n);
        return ans;
        
    }
};