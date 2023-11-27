#include <iostream>
#include <limits.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void BellmanFord(int graph[][3], int V, int E, int source) {
    int distance[V];
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 1; i <= V; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    const int V = 5;
    const int E = 7;
    int graph[E][3] = {{1, 2, 6}, {1, 3, 4}, {1, 4, 5}, {2, 5, -1},
                       {3, 2, -2}, {3, 5, 3}, {4, 3, -2}};

    int source = 1;
    BellmanFord(graph, V, E, source);
    return 0;
}

