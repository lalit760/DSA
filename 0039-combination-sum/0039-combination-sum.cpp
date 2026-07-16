class Solution {
public:
    vector<vector<int>>result;
    void helper(vector<int>& cad, int t, int idx,vector<int>&subset){
        if(t==0){
            result.push_back(subset);
            return;
        }
        if(idx==cad.size()) return;
        if(cad[idx] <= t){
            subset.push_back(cad[idx]); //pick & stay
            helper(cad,t-cad[idx],idx,subset);
            subset.pop_back(); // backtracking

            
        }
        helper(cad,t,idx+1,subset); //not pick & move
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        helper(candidates, target,0, subset);
        return result;
    }
};