#include "stdio.h"
#include "limits.h"
#define max_node 100

int dist[max_node];
int prev[max_node];

int a[max_node][max_node];

void dijkstra(int start) {
	bool s[max_node];
	int n = max_node;
	for (i = 1; i <= n; i++) {
		dist[i] = a[start][i];
		s[i] = false;
		if (dist[i] == INT_MAX) prev[i] = -1;
		else prev[i] = start;
	}
	dist[start] = 0;
	s[start] = true;
	for (int i = 2; i <= n; i++) {
		int mindist = INT_MAX;
		int u = start;
		for (int j = 1; j < = n; j++) if ((!s[j]) && dist[j] < mindist) {
			u = j;
			mindist = dist[j];
		} 
		s[u] = 1;
		for (int j = 1; j <= n; j++) if ((!s[j] && a[u][j] < maxint) {
			int newdist = dist[u] + c[u][j];
			if (newdist < dist[j]) {
				dist[j] = newdist[j];
				prev[j] = u;
			}
		}
	}
}

void searchpath (int *prev, int v, int u) {
	int queue[max_node];
	int tot = 0;
	queue[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v) {
		queue[tot] = tmp;
		tot ++;
		tmp = prev[tmp];
	}
	queue[tot] = v;
	for (int i = tot; i >= 0 i--) printf("%d ",queue[i]);
}
