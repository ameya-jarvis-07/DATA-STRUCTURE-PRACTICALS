#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

int main() {
    int vertices, edges, directed = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if (!directed) {
            adj[v][u] = 1;
        }
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start, vertices);
    printf("\n");

    return 0;
}
