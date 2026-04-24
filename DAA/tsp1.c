#include <stdio.h>
#include <limits.h>

#define N 4

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[N] = {0};
    int path[N + 1];
    int cost = 0;

    int current = 0;
    visited[current] = 1;
    path[0] = current;

    for (int i = 1; i < N; i++) {
        int next = -1;
        int minDist = INT_MAX;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[current][j] != 0 && dist[current][j] < minDist) {
                minDist = dist[current][j];
                next = j;
            }
        }

        visited[next] = 1;
        path[i] = next;
        cost += minDist;
        current = next;
    }

    cost += dist[current][0];
    path[N] = 0;

    printf("Greedy Method (Nearest Neighbor):\n");
    printf("Path: ");
    for (int i = 0; i <= N; i++) {
        printf("%d", path[i]);
        if (i < N) printf(" -> ");
    }

    printf("\nTotal Cost: %d\n", cost);

    return 0;
}