#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define max_node_count 100
#define init_node 0

typedef struct {
	int matrix[max_node_count][max_node_count];
	int node_count;
} graph;

graph example_graph;

void init_graph() {
	memset(example_graph.matrix, 0, sizeof(example_graph.matrix));
	example_graph.node_count = 0;
}

void read_graph() {
	int start, end;
	while (scanf("%d %d", &start, &end) && start != -1 && end != -1) {
		example_graph.matrix[start][end] = 1;
		example_graph.matrix[end][start] = 1;
		//assume connection is formed both ways
		example_graph.node_count = fmax(example_graph.node_count, start);
		example_graph.node_count = fmax(example_graph.node_count, end);
		//assume we use all integers below n before adding a new node
	}
	example_graph.node_count++;
}

void DFS(int cur_node);

int visited[max_node_count];

void doDFS() {
	memset(visited,0, sizeof(visited));
	printf("DFS ----------------------\n");
	visited[init_node] = 1;
	DFS(init_node);
	printf("--------------------------\n");
	return;
}

void DFS(int cur_node) {
	printf("%d\n", cur_node);
	for (int i = 0; i < example_graph.node_count; i++) 
		if ((!visited[i]) && (example_graph.matrix[cur_node][i])) {
			printf("found new connection : %d %d\n", cur_node, i);
			visited[i] = 1;
			DFS(i);
		}
}


int main () {
	freopen("Graph.in", "r", stdin);
	freopen("DFS.ans", "w", stdout);
	init_graph();
	read_graph();
	doDFS();
}
