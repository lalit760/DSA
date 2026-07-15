class Solution {
public:
    // graph making
    vector<list<int>>graph;
    void add_edge(int a, int b,bool bi_dir=true){
        graph[a].push_back(b);
        if(bi_dir){
            graph[b].push_back(a);
        }
    }

    int dfs(int node,unordered_set<int>&visited){
        visited.insert(node);
        int cnt = 1;
        for(auto neighbour: graph[node]){
            if(!visited.count(neighbour)){
                cnt += dfs(neighbour,visited);
            }
        }
        return cnt;
    }

    void cc(int n,unordered_set<int>&visited, vector<int>&save){
        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                int size = dfs(i,visited);
                save.push_back(size);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int size = edges.size();
        graph.resize(n,list<int>());
        for(int i=0;i<size;i++){
            add_edge(edges[i][0],edges[i][1]);
        }
        vector<int>save;
        unordered_set<int>visited;
        cc(n,visited,save);
        long long int ans=0;
        long long int rem = n;
        for(auto i : save){
            rem = rem-i;
            ans += i*rem;
        }
        return ans;
        
    }
};