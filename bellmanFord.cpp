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

vector <int> v[1000000];
int dis[1000000];
int n, m;

int main (void) {
	int i, j;
	sc (n), sc (m);

	for (i = 1; i < n+1; i++) {
		dis [i] = inf;
	}

	int from, to, w;

	for (i = 0; i < m; i++) {
		sc (from), sc (to), sc (w);
		v[i].push_back (from);
		v[i].push_back (to);
		v[i].push_back (w);
	}

	int s, t;
	sc (s), sc (t);
	dis[s] = 0;
	for (i = 0; i < n-1; i++) {
		j = 0;
		while (v[j].size() != 0) {
			if (dis[v[j][0]] < inf && dis[v[j][1]] > dis[v[j][0]] + v[j][2]) {
				dis[v[j][1]] = dis[v[j][0]] + v[j][2];
			}
			j++;
		}
	}
	bool negCycle = false;
	j = 0;
	while (v[j].size() != 0) {
		if (dis[v[j][0]] < inf && dis[v[j][1]] > dis[v[j][0]] + v[j][2]) {
			negCycle = true;
			break;
		}
		j++;
	}
	if (!negCycle)
		cout<<dis[t]<<endl;
	else {
		cout<<"Negative weight cycle found"<<endl;
	}
	return 0;
}
