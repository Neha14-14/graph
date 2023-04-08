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
vector<int> graph[1000000];
int dis[1000000];

void bfs (int s) {
	bool state[1000000];
	memset(state, false, sizeof(state));
	queue<int> q;
	q.push(s);
	state[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (int i = 0; i < graph[s].size(); i++) {
			if (!state[graph[s][i]]) {
				dis[graph[s][i]] = dis[s]+1;
				q.push(graph[s][i]);
				state[graph[s][i]] = true;
			}
		}
	}
	return ;
}

int main (void) {
	sc(n), sc(m);
	int i, j,x, y;

	for (i = 0; i < m; i++) {
		sc(x), sc(y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int s;
	sc(s);
	bfs(s);
	for (i = 0; i < n; i++) {
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	return 0;
}
