#include <stdio.h>
#include <limits.h>

#define N 4
#define VISITED_ALL (1 << N)

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << N][N];
int parent[1 << N][N];

int tsp(int mask, int pos) {
    if (mask == VISITED_ALL - 1)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {

            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);

            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = city;
            }
        }
    }

    return dp[mask][pos] = ans;
}

void printPath() {
    int mask = 1, pos = 0;

    printf("Path: 0 ");

    while (1) {
        int next = parent[mask][pos];
        if (next == -1) break;

        printf("-> %d ", next);
        mask |= (1 << next);
        pos = next;

        if (mask == VISITED_ALL - 1)
            break;
    }

    printf("-> 0\n");
}

int main() {

    // Initialize dp and parent
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
            parent[i][j] = -1;
        }
    }

    int minCost = tsp(1, 0);

    printf("Dynamic Programming (Bitmask):\n");
    printf("Minimum Cost: %d\n", minCost);

    printPath();

    return 0;
}