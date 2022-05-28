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
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(0);

/*........................ let's try one more time ........................*/

map<int, int> m;

bool factorization(int n) {
  if (n % 2 == 0) {
    if (m[2]) return 1;
    m[2] = 1;
    while (n % 2 == 0) n /= 2;
  }

  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      if (m[i]) return 1;
      m[i] = 1;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 2) {
    if (m[n]) return 1;
    m[n] = 1;
  }
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n;
    cin >> n;
    vi v(n, 0);
    for (auto& x : v) cin >> x;
    bool pairPrime = 1;
    for (auto x : v) {
      if (factorization(x)) {
        pairPrime = 0;
        break;
      }
    }
    if (pairPrime) {
      cout << "pairwise coprime" << nl;
      return 0;
    }

    int g = v[0];
    for (auto x : v) g = __gcd(g, x);
    if (g == 1) cout << "setwise coprime" << nl;
    else cout << "not coprime" << nl;
  }
  return 0;
}
