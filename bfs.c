#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure for an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph
void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add the reverse edge as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while (front != rear) {
        // Dequeue a vertex from the queue
        int currentVertex = queue[++front];

        printf("%d ", currentVertex);

        // Get all the adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                // Mark the adjacent vertex as visited and enqueue it
                graph->visited[adjVertex] = true;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    int vertices = 5;

    initGraph(&graph, vertices);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    // Perform BFS starting from vertex 0
    BFS(&graph, 0);

    return 0;
}
