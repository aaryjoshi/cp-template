#include<bits/stdc++.h>
// template<typename T>
// struct BIT {
//   int N_;
//   vector<T> F_;
//   BIT(int n) {
//     N_=n;
//     F_=vector<T>(n+1);
//   }
//   void update(int at, T val) {
//     for(;at<=N_;at+=at&-at)F_[at]+=val;
//   }
//   T query(int l, int r) {
//     if(l!=1) {
//       return query(1,r)-query(1,l-1);
//     }
//     T res=0;
//     for(;r>0;r-=r&-r)res+=F_[r];
//     return res;
//   }
// };

class BIT { // One-based indexing
    vector<int> bit;
public:
    BIT(int size=0) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [1..idx]
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};
