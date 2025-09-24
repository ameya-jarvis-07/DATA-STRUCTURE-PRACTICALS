#include <stdio.h>
#include <stdlib.h>

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

void bfs(struct Graph* graph, int start) {
    for (int i = 0; i < graph->vertices; i++) graph->visited[i] = 0;

    int queue[100], front = 0, rear = 0;
    queue[rear++] = start;
    graph->visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct Node* temp = graph->adjList[node];
        while (temp) {
            if (!graph->visited[temp->vertex]) {
                queue[rear++] = temp->vertex;
                graph->visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsRecursive(struct Graph* graph, int node) {
    graph->visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = graph->adjList[node];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            dfsRecursive(graph, temp->vertex);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int start) {
    for (int i = 0; i < graph->vertices; i++) graph->visited[i] = 0;

    printf("DFS Traversal: ");
    dfsRecursive(graph, start);
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

    bfs(graph, start);
    dfs(graph, start);

    return 0;
}
