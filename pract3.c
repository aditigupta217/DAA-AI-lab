#include <stdio.h>

int graph[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[5] = {0};

void DFS(int node) {
    int i;
    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < 5; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    printf("DFS Traversal starting from node 0:\n");
    DFS(0);
    return 0;
}
