#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#define MAX_VEX_NUM 100

short int adj[MAX_VEX_NUM][MAX_VEX_NUM];
int dist[MAX_VEX_NUM][MAX_VEX_NUM];
int pred[MAX_VEX_NUM][MAX_VEX_NUM];

void floyd_warshall (int vex_num) {
    for (int i = 0; i < vex_num; i++)
        for (int j = 0; j < vex_num; j++) {
            if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INT_MAX;
            pred[i][j] = j;
        }
    for (int mid = 0; mid < vex_num; mid++) 
        for (int start = 0; start < vex_num; start++)
            for (int end = 0; end < vex_num; end++) {
                long new_dist = (dist[start][mid] == INT_MAX || dist[mid][end] == INT_MAX ? INT_MAX : dist[start][mid] + dist[mid][end]);
                if (dist[start][end] > new_dist) {
                    dist[start][end] = new_dist;
                    pred[start][end] = pred[start][mid];
                }
            }
}

void path (int u, int v) {
    if (pred[u][v] == -1) return;
    printf("%d ", u);
    while (u != v) {
        u = pred[u][v];
        printf("%d ", u);
    }
}
