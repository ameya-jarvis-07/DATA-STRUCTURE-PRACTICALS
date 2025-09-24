#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void addEdge(int u, int v, int directed) {
    adj[u][v] = 1;
    if (!directed) {
        adj[v][u] = 1;
    }
}

void bfs(int start, int vertices) {
    for (int i = 0; i < vertices; i++) visited[i] = 0;

    front = rear = -1;
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front != rear) {
        int node = queue[++front];
        printf("%d ", node);

        for (int i = 0; i < vertices; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsRecursive(int node, int vertices) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < vertices; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfsRecursive(i, vertices);
        }
    }
}

void dfs(int start, int vertices) {
    for (int i = 0; i < vertices; i++) visited[i] = 0;

    printf("DFS Traversal: ");
    dfsRecursive(start, vertices);
    printf("\n");
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
    }

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v, directed);
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, vertices);
    dfs(start, vertices);

    return 0;
}
