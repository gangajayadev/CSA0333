#include <stdio.h>
#define INF 9999
#define SIZE 100

void dijkstra(int graph[SIZE][SIZE], int n, int start) {
    int distance[SIZE], visited[SIZE];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++) {
        printf("To %d: %d\n", i, distance[i]);
    }
}

int main() {
    int graph[SIZE][SIZE], n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no direct edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}

