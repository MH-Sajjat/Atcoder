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

vll v;

void precal() {
	v.pb(0);
	for (int start = 1; start <= 9; ++start) {
		for (int dif = -9; dif <= 9; ++dif) {
			ll num = 0;
			int d = start;
			for (int len = 1; len <= 18; ++len) {
				if (d < 0 or d > 9) break;
				num *= 10;
				num += d;
				d += dif;
				v.pb(num);
				// debug(num)
				if (d < 0 or d > 9) break;
			}
		}
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
  	precal();
  	ll n;
  	cin >> n;
  	auto it = lower_bound(all(v), n);
  	cout << *it << nl;
  }
  return 0;
}
