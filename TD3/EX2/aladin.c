#include <stdio.h>
#include <stdlib.h>
#include "aladin.h"

Graph* createGraph(int n) {
    Graph* g = malloc(sizeof(Graph));
    g->n = n;

    g->adj = malloc((n + 1) * sizeof(int*));
    g->adjSize = malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        g->adj[i] = NULL;
        g->adjSize[i] = 0;
    }

    return g;
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u] = realloc(g->adj[u], (g->adjSize[u] + 1) * sizeof(int));
    g->adj[u][g->adjSize[u]++] = v;

    g->adj[v] = realloc(g->adj[v], (g->adjSize[v] + 1) * sizeof(int));
    g->adj[v][g->adjSize[v]++] = u;
}

void freeGraph(Graph* g) {
    for (int i = 1; i <= g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g->adjSize);
    free(g);
}


void dfs(Graph* g, int node, int* visited) {
    visited[node] = 1;
    for (int i = 0; i < g->adjSize[node]; i++) {
        int next = g->adj[node][i];
        if (!visited[next])
            dfs(g, next, visited);
    }
}

int countKingdoms(Graph* g) {
    int* visited = calloc(g->n + 1, sizeof(int));
    int count = 0;

    for (int i = 1; i <= g->n; i++) {
        if (!visited[i]) {
            count++;
            dfs(g, i, visited);
        }
    }

    free(visited);
    return count;
}

int shortestPath(Graph* g, int start, int end) {
    int* dist = malloc((g->n + 1) * sizeof(int));
    for (int i = 1; i <= g->n; i++) dist[i] = -1;

    int *queue = malloc((g->n + 1) * sizeof(int));
    int front = 0, back = 0;

    queue[back++] = start;
    dist[start] = 0;

    while (front < back) {
        int node = queue[front++];

        if (node == end) break;

        for (int i = 0; i < g->adjSize[node]; i++) {
            int next = g->adj[node][i];
            if (dist[next] == -1) {
                dist[next] = dist[node] + 1;
                queue[back++] = next;
            }
        }
    }

    int result = dist[end];

    free(dist);
    free(queue);

    return result;
}
