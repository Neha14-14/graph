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

int n,m;
int arr[1000000], size[1000000];
pair<int, pint> graph[1000000];


void init ()
{
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = i;
		size[i] = 1;
	}
	return ;
}

int root (int a)
{
	while (arr[a] != a) {
		arr[a] = arr[arr[a]];
		a = arr[a];
	}
	return a;
}

void unionSet (int a, int b)
{
	int pa, pb;
	pa = root(a);
	pb = root (b);
	if(pa == pb){
		return ;
	}
	if (size[pa] < size[pb]) {
		arr[pa] = arr[pb];
		size[pb]+= size[pa];
	}else {
		arr[pb] = arr[pa];
		size[pa] += size[pb];
	}
	return ;
}

bool find (int a, int b)
{
	int root_a, root_b;
	root_a = root(a);
	root_b = root(b);
	if (root_b == root_a) {
		return true;
	}else {
		return false;
	}
}



int kruskal () {
	sort(graph, graph+m);
	int sum = 0;
	init();
	int i;
	for (i = 0; i < m; i++) {
		if (!find (graph[i].second.first, graph[i].second.second)) {
			unionSet(graph[i].second.first, graph[i].second.second);
			sum+=graph[i].first;
		}
	}
	return sum;
}

int main (void) {
	sc(n), sc(m);
	int i, x, y, w;
	for (i = 0; i < m; i++) {
		sc(x), sc(y), sc(w);
		graph[i] = mk(w, mk(x, y));
	}
	int sum = kruskal();
	pr(sum);
	return 0;
}
