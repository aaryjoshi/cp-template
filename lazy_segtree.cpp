#include<bits/stdc++.h>

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




struct segTree{
  vector<int> T,L;
  int n;
  segTree(int n){
    this->n=n;
    T.resize(4*n,0);
    L.resize(4*n,0);
  }

  void push(int v){
    L[v+v]+=L[v];
    L[v+v+1]+=L[v];
    L[v]=0;
  }

  void applyAggregate(int v,int tl,int tr){
    T[v]+=(L[v]*(tr-tl+1));
    if(tl!=tr)
      push(v);
    L[v]=0;
  }

  void build(vector<int> &arr,int v,int tl,int tr){
    if(tl==tr){
      T[v]=arr[tl];
      return;
    }
    int mid=(tl+tr)>>1;
    build(arr,v+v,tl,mid);
    build(arr,v+v+1,mid+1,tr);
    T[v]=T[v+v]+T[v+v+1];
  }

  int query(int v,int tl,int tr,int l,int r){
    applyAggregate(v,tl,tr);
    if(r<tl || l>tr)
      return 0;
    if(l<=tl and tr<=r){
      return T[v];
    }
    int mid=(tl+tr)>>1;
    return (query(v+v,tl,mid,l,r)+query(v+v+1,mid+1,tr,l,r));
  }

  void update(int val,int v,int tl,int tr,int l,int r){
    applyAggregate(v,tl,tr);
    if(r<tl || l>tr)
      return ;
    if(l<=tl and tr<=r){
      L[v]+=val;
      applyAggregate(v,tl,tr);
      return;
    }
    //lazy update ko niche push kar
    int mid=(tl+tr)>>1;
    update(val,v+v,tl,mid,l,r);
    update(val,v+v+1,mid+1,tr,l,r);
    //niche wale nodes pe lazy update karde
    T[v]=T[v+v]+T[v+v+1];
  }

  void build(vector<int> &arr){build(arr,1,0,n-1);};
  int query(int l,int r){return query(1,0,n-1,l,r);}
  void update(int val,int l,int r){update(val,1,0,n-1,l,r);}
};

