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

int n, m;
vector<int> g[1000000];
bool state[1000000];
int dis[1000000];

void dfs (int s, int ctr) {
	state[s] = true;
	dis[s] = ctr;
	for (int i = 0; i < g[s].size(); i++) {
		if (!state[g[s][i]]) {
				dfs (g[s][i], ctr);
		}
	}
}

int main (void) {
	sc(n), sc(m);
	int x, y, i;

	for (i = 0; i < m; i++) {
		sc(x), sc(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int ctr = 0;
	for (i = 0; i < n; i++) {
		if (!state[i]) {
			dfs  (i, ctr);
			ctr++;
		}
	}
	for (i = 0; i < n; i++) {
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	return 0;
}
