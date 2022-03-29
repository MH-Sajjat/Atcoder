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

map<int, int> m;
int cnt = 0;
int getID(int x) {
  if (!m[x]) m[x] = ++cnt;
  return m[x];
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
    vector<vi> nums(n + 2);

    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      int id = getID(x);
      nums[id].pb(i);
    }

    while (q--) {
      int x, k;
      cin >> x >> k;
      int id = getID(x);
      if (id > n or szof(nums[id]) < k) cout << -1 << nl;
      else cout << nums[id][k - 1] << nl;
    }
  }
  return 0;
}
