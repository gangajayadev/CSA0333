#include <stdio.h>
#define INF 9999
#define SIZE 100

void primMST(int graph[SIZE][SIZE], int n) {
    int selected[SIZE] = {0};
    int edge_count = 0;
    int i, j;

    selected[0] = 1;
    printf("Edges in MST:\n");

    while (edge_count < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = 1;
        edge_count++;
    }
}

int main() {
    int graph[SIZE][SIZE], n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    primMST(graph, n);

    return 0;
}

