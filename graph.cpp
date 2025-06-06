#include<bits/stdc++.h>


//dijkstra single source shortest
const int INF=1000000000;
vector<vector<pair<int,int>>> adj;
void dijkstra(int s,vector<int> &d,vector<int> &p){
    int n=adj.size();
    d.assign(n,INF);
    p.assign(n,-1);

    d[s]=0;
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});

    while(!q.empty()){
        int node=q.top().second;
        int node_d=q.top().first;
        q.pop();
        if(node_d!=d[node])
            continue;

        for(auto edge:adj[node]){
            int to=edge.first;
            int wt=edge.second;

            if(d[node]+wt<d[to]){
                d[to]=d[node]+wt;
                p[to]=node;
                q.push({d[to],to});
            }
        }
    }
}

//floydd warshall all source shortest
void allSourceShortest(){
    int n=adj.size();
    vector<vector<int>> d(n,vector<int>(n,INF));
    for(int node=0;node<n;node++){
        for(auto nei:adj[node]){
            d[node][nei.first]=min(d[node][nei.first],nei.second);
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
}

//belmann ford 
struct Edgef{
  int a, b, cost;
};
int n, m, v;
vector<Edgef> edges;
const int INF = 1000000000;
void solve(){
  vector<int> d(n, INF);
  d[v] = 0;
  for (;;) {
    bool any = false;

    for (Edgef e : edges)
      if (d[e.a] < INF)
        if (d[e.b] > d[e.a] + e.cost) {
          d[e.b] = d[e.a] + e.cost;
          any = true;
        }

    if (!any)
      break;
  }
}

//mst -> prims
struct Edge {
  int w = INF, to = -1;
  bool operator<(Edge const& other) const {
    return make_pair(w, to) < make_pair(other.w, other.to);
  }
};
int n;
vector<vector<Edge>> adjp;
void prim() {
  int total_weight = 0;
  vector<Edge> min_e(n);
  min_e[0].w = 0;
  set<Edge> q;
  q.insert({0, 0});
  vector<bool> selected(n, false);
  for (int i = 0; i < n; ++i) {
    if (q.empty()) {
      cout << "No MST!" << endl;
      exit(0);
    }

    int v = q.begin()->to;
    selected[v] = true;
    total_weight += q.begin()->w;
    q.erase(q.begin());

    if (min_e[v].to != -1)
      cout << v << " " << min_e[v].to << endl;

    for (Edge e : adjp[v]) {
      if (!selected[e.to] && e.w < min_e[e.to].w) {
        q.erase({min_e[e.to].w, e.to});
        min_e[e.to] = {e.w, v};
        q.insert({e.w, e.to});
      }
    }
  }
  cout << total_weight << endl;
}

//toposort

//lca using binary lifting 
//log(n) per query
struct Blift{
  int n,l;
  vector<vector<int>> adj;

  vector<vector<int>> up;
  vector<int> tin,tout;

  int timer=0;
  void dfs(int node,int par){
    up[node][0]=par;
    for(int i=1;i<=l;i++){
      up[node][i]=up[up[node][i-1]][i-1];
    }

    tin[node]=++timer;
    for(auto nei:adj[node]){
      if(nei==par)
        continue;
      dfs(nei,node);
    }
    tout[node]=++timer;
  }

  bool is_ancestor(int u,int v){
    return (tin[u]<=tin[v] && tout[u]>=tin[v]);
  }

  int lca(int u,int v){
    if(is_ancestor(u,v))
      return u;
    if(is_ancestor(v,u))
      return v;

    for(int i=l;i>=0;i--){
      if(!is_ancestor(up[u][i],v))
        u=up[u][i];
    }
    //we are just below the lca
    return up[u][0];
  }

  void precomp(int root){
    tin.resize(n,0);
    tout.resize(n,0);
    timer=0;
    int l=ceil(log2(n));
    up.assign(n,vector<int>(l+1));
    dfs(root,root);
  }
};


//lca using euler tour
//O(1) per query



//euler tour
