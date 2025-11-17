#include <stdio.h>
#include <stdlib.h>
#include "aladin.h"

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Graph* g = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    int A, B;
    scanf("%d %d", &A, &B);

    int kingdoms = countKingdoms(g);

    int shortest = shortestPath(g, A, B);

    printf("%d\n", kingdoms);
    printf("%d\n", shortest);

    freeGraph(g);
    return 0;
}
