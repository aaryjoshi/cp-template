// template <typename T>
// struct BIT_2D {
//   int N, M;
//   vector<vector<T>>tree;
//   BIT_2D(int n, int m) {
//     N = n;
//     M = m;
//     tree.assign(N + 1, vector<T>(M + 1, 0));
//   }
//   void update(int x, int y,  T val) {
//     for(int i = x; i <= N; i += (i & (-i))) {
//       for(int j = y; j <= M; j += (j & (-j))) {
//         tree[i][j] += val;
//       }
//     }
//   }
//   T sum(int xl, int yl, int xr, int yr) {
//     if(!(xl == 1 && yl == 1)) {
//       return sum(1, 1, xr, yr) - sum(1, 1, xl - 1, yr) - sum(1, 1, xr, yl - 1) + sum(1, 1, xl - 1, yl - 1);
//     }
//     T res = 0;
//     for(int i = xr; i > 0; i -= (i & (-i))) {
//       for(int j = yr; j > 0; j -= (j & (-j))) {
//         res += tree[i][j];
//       }
//     }
//     return res;
//   }
// };
