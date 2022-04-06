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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
  	string s;
  	cin >> s;
  	int k;
  	cin >> k;
  	int n = szof(s);
  	s = '?' + s;
  	vi v;
  	int res = 0;
  	vi pre(n + 2, 0), post(n + 2, 0);
  	for (int i = 1; i <= n; ++i) {
  		if (s[i] == '.') {
  			pre[i] = 0;
  			v.pb(i);
  		} else pre[i] = pre[i - 1] + 1;
  		res = max(res, pre[i]);
  	}
  	for (int i = n; i >= 1; --i) {
  		if (s[i] == '.') post[i] = 0;
  		else post[i] = post[i + 1] + 1;
  	}

  	int m = szof(v) - 1;

  	for (int i = 0; i <= m; ++i) {
  		int last = min(m, i + k - 1);
  		// debug(post[v[last] + 1])
  		int sub = v[last] - v[i] + 1 + pre[v[i] - 1] + post[v[last] + 1];
  		res = max(res, sub);
  	}
  	cout << res << nl;
  }
  return 0;
}
