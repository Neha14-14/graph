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
vector<pint> g[1000000];
multimap<int, int> mp;

int prims (int s) {
	bool state[1000000];
	mp.clear();
	mp.insert (mk(0, s));
	int sum = 0, t;
	memset(state, false, sizeof(state));
	while (!mp.empty()) {
		s = (*(mp.begin())).second;
		if (state[s]) {
			mp.erase (mp.begin());
			continue;
		}
		t = (*(mp.begin())).first;
		sum+=t;
	//	cout<<s<<" "<<t<<endl;
		mp.erase (mp.begin());
		state[s] = true;
		for (int i = 0; i < g[s].size(); i++) {
			int a, b;
			a = g[s][i].first;
			b = g[s][i].second;
			if(!state[a]) {
				mp.insert(mk(b, a));
			}
		}
	}
	return sum;
}

int main (void) {
	sc(n), sc(m);
	int i, x, y, w;
	for (i = 0; i < m; i++) {
		sc(x), sc(y), sc(w);
		g[y].push_back(mk(x,w));
		g[x].push_back(mk(y,w));
	}
	int ans = prims(0);
	pr(ans);
	return 0;
}
