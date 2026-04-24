#include <stdio.h>

int adj[5][5] = {
    {1, 2},
    {0, 3},
    {0, 3, 4},
    {1, 2, 4},
    {2, 3}
};

int adjSize[5] = {2, 2, 3, 3, 2};
int visited[5] = {0};
int queue[5], front = 0, rear = 0;

void BFS(int start) {
    int i, node;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        node = queue[front++];
        printf("%d ", node);

        for (i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            if (visited[neighbor] == 0) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }
}

int main() {
    printf("BFS Traversal starting from node 0:\n");
    BFS(0);
    return 0;
}
