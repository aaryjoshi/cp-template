#include<bits/stdc++.h>

//bit trie
struct trie{
  vector<vector<int>> t;
  vector<int> cnt;
  int N ,root=0;

  int newNode(){
    int x=++root;
    t[x][0]=t[x][1]=0;
    cnt[x]=0;
    return x;
  }

  trie(int n){
    this->N=n;
    t.resize(N*30,vector<int>(2));
    cnt.resize(N*30);
    newNode();
  }

  void add(int x,int xcnt) {
    int curr=1;
    for (int i = 29; i >= 0; i--) {
      int &p=t[curr][x >> i & 1];
      if(!p) {
        p=newNode();
      }
      curr=p;
      cnt[curr]+=xcnt;
    }
  }

  int mxXor(int x){
    int curr=1;
    int ans=0;
    for(int bit=29;bit>=0;bit--){
      int need=(x>>bit&1)^1;
      if(cnt[t[curr][need]]){
        ans|=(1<<bit);
        curr=t[curr][need];
      }
      else{
        curr=t[curr][need^1];
      }
    }
    return ans;
  }
};