#include <iostream>
#include <limits.h>

using namespace std;

const int N = 4; // Number of vertices in the graph

// Function to solve the Traveling Salesman Problem using dynamic programming
int tsp(int graph[N][N], int mask, int pos, int dp[][1 << N]) {
    if (mask == (1 << N) - 1) {
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }
    dp[pos][mask] = ans;
    return ans;
}

int main() {
    int graph[N][N] = {{0, 16, 11, 6},
                       {8, 0, 13, 16},
                       {4, 7, 0, 9},
                       {5, 12, 2, 0}};

    int dp[N][1 << N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }

    int mask = 1;
    int pos = 0;
    int minCost = tsp(graph, mask, pos, dp);

    cout << "The minimum cost of the TSP is: " << minCost << endl;

    return 0;
}

