v(pint) v[1000000];
int ans[1000000];
multimap<int, int> mp;
int n, m;

void dijsktra(int s) {
	//int state[100010];
	///memset(state, false, sizeof(state));
	fill(ans, ans+n+5, inf);
	mp.clear();
	mp.insert(mk(0, s));
	ans[s] = 0;
	bool state[n+1];
	mem(state, false);
	while (!mp.empty()) {
		s = ((*mp.begin()).second);
		mp.erase (mp.begin());
		if (state[s]) {
			continue;
		}
		state[s] = true;
		for (int i = 0; i < v[s].size(); i++) {
			int a, b;
			a = v[s][i].first;
			b = v[s][i].second;
			if (!state[a] && ans[a] > ans[s] + b) {
				ans[a] = ans[s]+b;
				mp.insert(mk(ans[a], a));
			}
		}
	}
	return ;
}
