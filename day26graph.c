#include <stdio.h>

int adj[10][10], visited[10], n;

void dfs(int node) {
    int i;

    printf("%d", node);
    visited[node] = 1;

    for (i = 0; i < n; i++) {
        if (adj[node][i] == 1 && ! visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n -1);
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
    
}