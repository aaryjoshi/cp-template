struct comb{
  vector<int> factorial, invFactorial;

  comb(int n){
    factorial.resize(n+1,0);
    invFactorial.resize(n+1,0);
    
    getFactorials(n);
  }

  ll power(ll a, ll n){
    ll ans = 1;
    while (n){
      if (n & 1)
        ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      n >>= 1;
    }
    return ans;
  }

  ll inverse(ll a){
    return power(a, MOD - 2);
  }

  void getFactorials(int n){
    factorial[0] = 1;
    invFactorial[0] = 1;
    for (ll i = 1; i <= n; i++){
      factorial[i] = (factorial[i - 1] * i) % MOD;
      invFactorial[i] = inverse(factorial[i]);
    }
  }

  ll nCr(ll n, ll r){
    if (r < 0)
      return 0;
    if (r > n)
      return 0;
    ll ans = (invFactorial[r] * invFactorial[n - r]) % MOD;
    ans = (ans * factorial[n]) % MOD;
    return ans;
  }

  ll nPr(ll n, ll r){
    if (r < 0)
      return 0;
    if (r > n)
      return 0;
    ll ans = (invFactorial[n - r]) % MOD;
    ans = (ans * factorial[n]) % MOD;
    return ans;
  }
};
