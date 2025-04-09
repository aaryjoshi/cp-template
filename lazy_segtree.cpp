template<typename T, typename F>
struct Segtree {
  vector<T> t;
  vector<F> lz;
  T def;
  int n;
  Segtree(){}
  Segtree(int N) {
    n=N;
    t=vector<T>(4*n);
    lz=vector<F>(4*n);
  }
  void build(vector<T> &arr, int tl, int tr, int v) {
    lz[v]=F(tl,tr);
    if(tl==tr) {
      t[v]=arr[tl];
      return;
    }
    int tm=(tl+tr)/2;
    build(arr,tl,tm,2*v);
    build(arr,tm+1,tr,2*v+1);
    t[v]=t[2*v]+t[2*v+1];
  }
  
  void push(int v) {
    lz[2*v].compose(lz[v]);
    lz[2*v+1].compose(lz[v]);
    t[v]=lz[v].applyAggregate(t[v]);
    int l=lz[v].l,r=lz[v].r;
    lz[v]=F(l,r);
  }
  T query(int l, int r, int tl, int tr, int v) {
    if(l>tr or r<tl)return def;
    if(l<=tl and tr<=r)return lz[v].applyAggregate(t[v]);
    push(v);
    int tm=(tl+tr)/2;
    return query(l,r,tl,tm,2*v)+query(l,r,tm+1,tr,2*v+1);
  }
  void update(int l, int r, F upd, int tl, int tr, int v) {
    if(r<tl or tr<l)return;
    if(l<=tl and tr<=r) {
      lz[v].compose(upd);
      return;
    }
    int tm=(tl+tr)/2; 
    push(v);
    update(l,r,upd,tl,tm,2*v);
    update(l,r,upd,tm+1,tr,2*v+1);
    t[v]=lz[2*v].applyAggregate(t[2*v])+lz[2*v+1].applyAggregate(t[2*v+1]);
  }
  void update(int at, T val, int tl, int tr, int v) {
    if(tl==tr) {
      t[v]=val;
      lz[v]=F(tl,tr);
      return;
    }
    int tm=(tl+tr)/2; 
    push(v);
    if(at<=tm)update(at,val,tl,tm,2*v);
    else update(at,val,tm+1,tr,2*v+1);
    t[v]=lz[2*v].applyAggregate(t[2*v])+lz[2*v+1].applyAggregate(t[2*v+1]);
  }
  T query(int l, int r){return query(l,r,0,n-1,1);}
  void update(int l, int r, F upd){update(l,r,upd,0,n-1,1);}
  void update(int at, T val){update(at,val,0,n-1,1);}
  void build(vector<T> &arr){build(arr,0,n-1,1);}
};