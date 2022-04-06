#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
const double EPS  = (double) 1e-9;

#define debug(x)  cerr << #x << " = " << x << '\n';
#define all(x)    x.begin(), x.end()
#define szof(x)   (int) x.size()
#define ff        first
#define ss        second
#define pb        push_back
#define mp        make_pair
#define PI        acos(-1.0)
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(nullptr);

/*........................ let's try one more time ........................*/
#ifdef LOCAL
     #define error(...) __f(#__VA_ARGS__, __VA_ARGS__);
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " = " << arg1 <<" ";
        __f(comma+1, args...);
    }
#else
    #define error(...)
#endif

vi g[N];
vector<bool> vis(N, 0);
int one = 0, two = 0, total = 0;

void dfs(int u) {
	int s = szof(g[u]);
	error(u, s)
	vis[u] = 1;
	total++;
	one += (s == 1);
	two += (s == 2);
	for (auto v : g[u]) {
		if (!vis[v]) dfs(v);
	}
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
  	int n, q;
  	cin >> n >> q;
  	// error(n, q)
  	vi cnt(n + 2, 0);
  	while (q--) {
  		int u, v;
  		cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}

  	// error(n, q)

  	bool valid = 1;

  	for (int i = 1; i <= n; ++i) {
  		// error(i)
  		if (!vis[i]) {
  			one = two = total = 0;
  			dfs(i);
  			error(i, one, two, total)
  			if (total == 1) continue;
  			if ((one != 2) or two != (total - 2)) valid = 0;
  		}
  	}

  	if (valid) cout << "Yes" << nl;
  	else cout << "No" << nl;
  }
  return 0;
}
