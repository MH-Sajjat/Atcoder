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

vector<string> bin(65);
string sum = "0";

void add(int pos) {
  string t = bin[pos];
  int n = szof(sum) - 1, m = szof(t) - 1;
  string temp = "";
  int d = 0;
  while (n >= 0 and m >= 0) {
    d += (sum[n] - '0');
    n--;
    d += (t[m] - '0');
    m--;
    temp += ((d % 10) + '0');
    d /= 10;
  }

  while (n >= 0) {
    d += (sum[n] - '0');
    n--;
    temp += ((d % 10) + '0');
    d /= 10;
  }

  while (m >= 0) {
    d += (t[m] - '0');
    m--;
    temp += ((d % 10) + '0');
    d /= 10;
  }

  while (d) {
    temp += ((d % 10) + '0');
    d /= 10;
  }

  while (temp.back() == '0') temp.pop_back();
  reverse(all(temp));
  sum = temp;

}

void precal() {
  bin[0] = "0";
  string s = "2";
  for (int i = 1; i <= 64; ++i) {
    bin[i] = s;
    s += '0';
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
    precal();
    ll n;
    cin >> n;
    int cnt = 1;
    while (n) {
      if (n & 1) add(cnt);
      cnt++;
      n /= 2;
    }
    cout << sum << nl;
  }
  return 0;
}
