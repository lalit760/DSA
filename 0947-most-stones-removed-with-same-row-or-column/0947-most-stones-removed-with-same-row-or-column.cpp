class Solution {
public:
    vector<int> parent,rank;
    int find(int x){  // to find parent of x
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x]; //path comression
    }

    void Union(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa==pb) return;

        // union by rank
        if(rank[pa] >= rank[pb]){
            parent[pb] = pa;
            rank[pa]++; // size increment
        }
        else{
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n); //initialization of vectors parent and rank
        rank.resize(n,0); //rank is 0 initially

        for(int i=0;i<n;i++){
            parent[i] = i; //self parenting
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) { //our condition
                    Union(i,j);
                }
            }
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(find(i)==i) cc++;               
        }
        return n-cc;
    }
};