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
const int MOD     = (int) 1048576;
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

vi par(MOD + 2, 0);
vll res(MOD, -1);

int root(int x) {
  if (res[x] == -1) return x;
  return par[x] = root(par[x]);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    for (int i = 0; i <= 1048576; ++i) {
      par[i] = (i + 1) % MOD;
    }
    
    int q;
    cin >> q;
    while (q--) {
      int t;
      cin >> t;
      ll x;
      cin >> x;
      if (t == 2) {
        cout << res[x % MOD] << nl;
        continue;
      }
      int h = x % MOD;
      int idx = root(h);
      res[idx] = x;
    }
  }
  return 0;
}
