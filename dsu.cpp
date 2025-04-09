template<typename T>
struct DSU{
  vector<T> sz,rank,par;

  DSU(int n){
    sz.resize(n+1,0);rank.resize(n+1,0);par.resize(n+1,0);
    for(T i=1;i<=n;i++){
      par[i]=i;
      sz[i]=1;
    }
  }

  T findUltPar(int curr){
    if(curr==par[curr]) 
      return curr;
    
    return par[curr]=findUltPar(par[curr]);
  }

  void unioBySz(T u,T v){
    T ultpr_u=findUltPar(u);
    T ultpr_v=findUltPar(v);

    if(ultpr_u==ultpr_v){
      return;
    }

    if(sz[ultpr_u]<sz[ultpr_v]){
      par[ultpr_u]=ultpr_v;
      sz[ultpr_v]+=sz[ultpr_u];
    }
    else{
      par[ultpr_v]=ultpr_u;
      sz[ultpr_u]+=sz[ultpr_v];
    }
  }


  void unionByRank(T u,T v){
    T ultpr_u=findUltPar(u);
    T ultpr_v=findUltPar(v);

    if(ultpr_u==ultpr_v){
      return;
    }

    if(rank[ultpr_u]<rank[ultpr_v]){
      par[ultpr_u]=par[ultpr_v];
    }
    else if(rank[ultpr_u]>rank[ultpr_v]){
      par[ultpr_v]=par[ultpr_u];
    }
    else {
      par[ultpr_v] = ultpr_u; 
      rank[ultpr_u]++; 
    }
  }

  T cp_sz(T curr){
    return sz[findUltPar(curr)];
  }

  T cp_rank(T curr){
    return rank[findUltPar(curr)];
  }
};
