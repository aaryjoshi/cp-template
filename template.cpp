//General template//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define repa(i, a, b) for (int i = a; i < b; i++)
#define rep(i, b) repa(i, 0, b)
#define el '\n'
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef pair<int, int> pi;
const ll MOD = 998244353;
const ll INF=1e18;
template <class T>
void print(const vector<T> V) {
    for (int i = 1; i < (int)V.size(); i++)
        cout << V[i] << " ";
    cout << el;
}



//BITMASK FUNC//
#define msb(x) __builtin_clz(x); // 32 bit
#define lsb(x) __builtin_ctz(x);
#define popcnt(x) __builtin_popcount(x);
#define parity(x) __builtin_parity(x);

//ORDERED SET//
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>


//CLOCK//
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


//ordered set
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



//FENWICK TREE  range update point query// 
struct FenwickTree {
    vector<int> bit;  
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

	void add(int idx, int val) {
    for (; idx <n; idx += idx & -idx)
        bit[idx] += val;
    }

	void range_add(int l, int r, int val){
		add(l, val);
		add(r + 1, -val);
	}

	int point_query(int idx){
		int ret = 0;
		for (; idx >=0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
};


//AllThatIKnow(){
//if nothing works try greedy 
//just check the necessary conditions 
//
//}





//special functions
//merge(all(a),all(b));

 
//INPUT TXT//
int main(){

auto begin = std::chrono::high_resolution_clock::now();
auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout); 
#endif // ONLINE_JUDGE
}

