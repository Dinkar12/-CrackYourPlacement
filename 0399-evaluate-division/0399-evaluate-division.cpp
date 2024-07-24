double bfs(string start,string end,map<string,vector<string>>&graph,map<pair<string,string>,double>&mp){
    if(graph[start].empty() || graph[end].empty()) return -1.0;
    if(start==end) return 1.0;
    map<string,string>parent;
    queue<string>q;
    q.push(start);
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        if(t==end){
            double res=1.0;
            while(t!=start){
                res*=mp[{parent[t],t}];
                t=parent[t];
            }
            return res;
        }
        for(auto x:graph[t]){
            if(x!=parent[t] && !parent[x].length()){
                parent[x]=t;
                q.push(x);
            }
        }
    }
    return -1.0;
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>res;
        map<string,vector<string>>graph;
        map<pair<string,string>,double>mp;
        for(int i=0;i<values.size();i++){
            auto x=equations[i];
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            mp[{x[0],x[1]}]=values[i];
            mp[{x[1],x[0]}]=1.0/values[i];
        }
        for(auto x:queries){
            res.push_back(bfs(x[0],x[1],graph,mp));
        }
        return res;
    }
};