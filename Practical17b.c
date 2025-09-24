#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjList;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int u, int v, int directed) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    if (!directed) {
        newNode = createNode(u);
        newNode->next = graph->adjList[v];
        graph->adjList[v] = newNode;
    }
}

void dfsStack(struct Graph* graph, int start) {
    int stack[MAX], top = -1;
    for (int i = 0; i < graph->vertices; i++) graph->visited[i] = 0;

    stack[++top] = start;
    printf("DFS Traversal (Stack): ");

    while (top != -1) {
        int node = stack[top--];

        if (!graph->visited[node]) {
            printf("%d ", node);
            graph->visited[node] = 1;

            struct Node* temp = graph->adjList[node];
            int neighbors[MAX], count = 0;
            while (temp) {
                if (!graph->visited[temp->vertex]) {
                    neighbors[count++] = temp->vertex;
                }
                temp = temp->next;
            }
            for (int i = count - 1; i >= 0; i--) {
                stack[++top] = neighbors[i];
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, directed = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, directed);
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dfsStack(graph, start);

    return 0;
}
