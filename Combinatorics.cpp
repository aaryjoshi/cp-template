#include<bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;

ll euclid(ll a, ll b, ll &x, ll &y) {
  if (!b) return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y, x);
  return y -= a/b * x, d;
}
const ll mod = 17; // change to something e l s e
struct Mint {
  ll x;
  Mint(ll xx) : x(xx) { }
  Mint operator+(Mint b) { return Mint((x + b.x) % mod); }
  Mint operator-(Mint b) { return Mint((x - b.x + mod) % mod); }
  Mint operator*(Mint b) { return Mint((x * b.x) % mod); }
  Mint operator/(Mint b) { return *this * invert(b); }
  Mint invert(Mint a) {
  ll x, y, g = euclid(a.x, mod, x, y);
  assert(g == 1); return Mint((x + mod) % mod);
  }
  Mint operator^(ll e) {
  if (!e) return Mint(1);
  Mint r = *this ^ (e / 2); r = r * r;
  return e&1 ? *this * r : r;
  }
} ;


struct comb{
  vector<int> factorial, invFactorial;

  comb(int n){
    factorial.resize(n+1,0);
    invFactorial.resize(n+1,0);
    
    getFactorials(n);
  }

  long long power(long long a, long long n){
    long long ans = 1;
    while (n){
      if (n & 1)
        ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      n >>= 1;
    }
    return ans;
  }

  long long inverse(long long a){
    return power(a, MOD - 2);
  }

  void getFactorials(int n){
    factorial[0] = 1;
    invFactorial[0] = 1;
    for (long long i = 1; i <= n; i++){
      factorial[i] = (factorial[i - 1] * i) % MOD;
      invFactorial[i] = inverse(factorial[i]);
    }
  }

  long long nCr(long long n, long long r){
    if (r < 0)
      return 0;
    if (r > n)
      return 0;
    long long ans = (invFactorial[r] * invFactorial[n - r]) % MOD;
    ans = (ans * factorial[n]) % MOD;
    return ans;
  }

  long long nPr(long long n, long long r){
    if (r < 0)
      return 0;
    if (r > n)
      return 0;
    long long ans = (invFactorial[n - r]) % MOD;
    ans = (ans * factorial[n]) % MOD;
    return ans;
  }
};
