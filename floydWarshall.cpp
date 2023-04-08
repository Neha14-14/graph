#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define mk(a, b) make_pair(a, b)
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll

int g[1000][1000];
int papa[1000][1000];
int n, m;

void flodWarShall () {
	int i, j, k;

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
					papa[i][j] = papa[k][j];
				}
			}
		}
	}
}

int main (void) {

	sc (n), sc (m);

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			g[i][j] = inf;
			papa[i][j] = -1;
		}
	}

	int from, to, w;

	for (i = 0; i < m; i++) {
		sc (from), sc (to), sc (w);
		g[from][to] = w;
		papa[i][j] = i;
	}

	flodWarShall ();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
