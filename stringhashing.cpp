#include<bits/stdc++.h>

/** @return a random integer between 0 and INT64_MAX */
long long rng() {
  static std::mt19937 gen(
    std::chrono::steady_clock::now().time_since_epoch().count());
  return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

//basic::
struct HASHING {
    int getRandomNumber(int l, int r) {
        random_device rd;   
        mt19937 gen(rd());  
        uniform_int_distribution<> dis(l, r);  
        return dis(gen);
    }

    long long rng() {
        static std::mt19937 gen(
        std::chrono::steady_clock::now().time_since_epoch().count());
        return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
    }

    const int MOD1=1e9+7, MOD2=1e9+9,BASE1=getRandomNumber(31,1e8),BASE2=getRandomNumber(31,1e8);
    vector<pair<int, int>> hashes, Pow;
    int n;

    HASHING(string st){
        this->n=st.size();
        hashes.assign(n + 1, {0, 0});
        Pow.assign(n+ 1, {1, 1});

        for (int i = 0; i < n; i++){
        hashes[i + 1] = {(1ll * hashes[i].first * BASE1 + (st[i] - 'a' + 1)) % MOD1,
                        (1ll * hashes[i].second * BASE2 + (st[i] - 'a' + 1)) % MOD2};
        Pow[i + 1] = {(1ll * Pow[i].first * BASE1) % MOD1,
                        (1ll * Pow[i].second * BASE2) % MOD2};
        }
    }

    pair<int, int> get_hash(int l, int r){
        l++, r++;
        int hash1=(hashes[r].first-(1ll * hashes[l - 1].first * Pow[r - l + 1].first) % MOD1 + MOD1) % MOD1;
        int hash2=(hashes[r].second-(1ll * hashes[l - 1].second * Pow[r - l + 1].second) % MOD2 + MOD2) % MOD2;

        return {hash1, hash2};
    }
};


//advanced::
#define MAXLEN 1000010

constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];
int64_t modmul(uint64_t a, uint64_t b){
  uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

        for (int i = n; i >= 1; i--){
            suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }
    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};