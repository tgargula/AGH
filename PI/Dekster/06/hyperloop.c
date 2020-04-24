#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool DFS (bool **tab, bool *visited, int a, int b, int n) {
    visited[a] = true;
    if (tab[a][b]) return true;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (tab[a][i] && !visited[i]) flag = flag || DFS(tab, visited, i, b, n); 
    }
    return flag;
}

int main() {

    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);

    bool **tab = malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) tab[i] = malloc(n * sizeof(bool));

    bool *visited = malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tab[i][j] = false;
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        tab[a][b] = tab[b][a] = true;
    }

    for (int i = 0; i < p; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = 0; i < n; i++) visited[i] = false;
        if (DFS(tab, visited, a, b, n)) printf("YES\n");
        else printf("NO\n");
    }


    for (int i = 0; i < n; i++) free(tab[i]);
    free(tab);
    free(visited);

    return 0;

}