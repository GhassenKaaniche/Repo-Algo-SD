typedef struct {
    int n;              
    int **adj;          
    int *adjSize;       
} Graph;

Graph* createGraph(int n);
void addEdge(Graph* g, int u, int v);
void freeGraph(Graph* g);

int countKingdoms(Graph* g);
int shortestPath(Graph* g, int start, int end);