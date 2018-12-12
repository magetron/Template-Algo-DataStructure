#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define max_node_count 100
#define max_queue_length 100
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

int visited[max_node_count];

typedef struct {
	int key[max_node_count];
	int front, end;
	int count;
} queue;

queue q;

void init_queue() {
	memset(q.key, 0, sizeof(q.key));
	q.front = 0;
	q.end = 0;
	q.count = 0;
}

void in_queue(int key) {
	q.key[q.end] = key;
	q.end ++;
	if (q.end == max_node_count) q.end = 0;
	q.count ++;
}

int pop_queue() {
	q.front ++;
	q.count --;
	if (q.front == max_node_count) {
		q.front = 0;
		return q.key[max_node_count - 1];
	} else return q.key[q.front - 1];
	return 0;
}

void BFS();

void doBFS() {
	init_queue();
	memset(visited, 0, sizeof(visited));
	printf("BFS-----------------------\n");
	visited[init_node] = 1;
	in_queue(init_node);
	BFS();
	printf("---------------------------\n");
	return;
}
	
void BFS() {
	while (q.count) {
		int tmp = pop_queue();
		printf("%d\n", tmp);
		for (int i = 0; i < example_graph.node_count; i++) 
			if ((example_graph.matrix[tmp][i] == 1) && (!visited[i])) {
				in_queue(i);
				visited[i] = 1;
			}
	}
}
		
int main () {
	freopen("Graph.in", "r", stdin);
	freopen("BFS.ans", "w", stdout);
	init_graph();
	read_graph();
	doBFS();
}
	
