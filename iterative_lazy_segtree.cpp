template<typename T, typename F>
struct segment_tree {
  int n, h;
  vector<T> t;
  vector<F> lz;
  segment_tree(int N) {
    n=N;
    h=__lg(n);
    t.resize(2*n);
    lz.resize(n);
  }
  segment_tree(vector<T> &a) {
    n=a.size();
    h=__lg(n);
    t.resize(2*n);
    lz.resize(n);
    for(int i = 0;i<n;i++)
      t[i+n]=a[i];
    for(int i = n-1;i>0;i--)t[i] = t[2*i] + t[2*i+1];
  }
  void apply(int v,  F upd) {
    t[v]=upd.applyAggregate(t[v]);
    if(v<n)lz[v].compose(upd);
  }
  void push(int v) {
    for(int s = h;s>0;s--) {
      int i = v>>s;
      apply(2*i, lz[i]);
      apply(2*i+1, lz[i]);
      lz[i]=F();
    }
  }
  void pull(int v) {
    while(v>1) {
      v>>=1;
      t[v] = lz[v].applyAggregate(t[2*v]+t[2*v+1]);
    }
  }
  void update(int pos, T val) {
    pos+=n;
    push(pos);
    for(t[pos]=val;pos>>=1;)
      t[pos] = t[2*pos] + t[2*pos+1];
  }
  void update(int l, int r, const F& upd) {
    l+=n,r+=n+1;
    push(l);
    push(r-1);
    int tmpl=l, tmpr=r;
    for(;l<r;l>>=1,r>>=1) {
      if(l&1) {
        apply(l, upd);
        l++;
      }
      if(r&1) {
        r--;
        apply(r, upd);
      }
    }
    pull(tmpl);
    pull(tmpr-1);
  }
  T query(int l, int r) {
    l+=n,r+=n+1;
    push(l);
    push(r-1);
    T resl, resr;
    bool L=0,R=0;
    for(;l<r;l>>=1,r>>=1) {
      if(l&1){
        if(L)
          resl = resl + t[l++];
        else resl=t[l++];
        L=1;
      }
      if(r&1) {
        if(R)
          resr = t[--r] + resr;
        else resr=t[--r];
        R=1;
      }
    }
    if(!L)return resr;
    if(!R)return resl;
    return resl + resr;
  }
};
