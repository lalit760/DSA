class Solution {
public:
    vector<list<int>>graph;
    void add_edge(int a, int b, bool bi_dir=true){ // graph created
        graph[a].push_back(b);
        if(bi_dir){
            graph[b].push_back(a);
        }
    }
    void topoBFS(int numCourses,vector<list<int>>&graph ,vector<int>&ans){
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){ //going to every vertex of the graph
            for(auto neighbour:graph[i]){
                indegree[neighbour]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour:graph[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses, list<int>());
        for(int i=0;i<prerequisites.size();i++){
            add_edge(prerequisites[i][1],prerequisites[i][0],false);
        }
        vector<int>ans;
        topoBFS(numCourses,graph,ans);
        if(ans.size() == numCourses) return true;
        return false;
    }
};