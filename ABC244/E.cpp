
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
const int MOD     = (int) 998244353;
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

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

/*........................ let's try one more time ........................*/

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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<pii> edge(M, {0, 0});
    for (auto &p : edge) {
      cin >> p.ff >> p.ss;
    }

    vector<vector<vi>> dp(2005, vector<vi>(2005, vi(2, 0)));
    dp[0][S][0] = 1;
    for (int i = 0; i < K; ++i) {
      for (auto p : edge) {
        int u = p.ff, v = p.ss;
        for (auto x : {0, 1}) {
          dp[i + 1][u][x ^ (u == X)] = add(dp[i + 1][u][x ^ (u == X)], dp[i][v][x], MOD);
          dp[i + 1][v][x ^ (v == X)] = add(dp[i + 1][v][x ^ (v == X)], dp[i][u][x], MOD);
        }
      }
    }

    cout << dp[K][T][0] << nl;
  }
  return 0;
}
