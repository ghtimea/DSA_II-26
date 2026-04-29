#include <stdio.h>

int n, m;
int hegy[20][20];
int memo[20][20];
int max_hossz = -1;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void keres(int r, int c, int aktualis_hossz) {
    if (r == n - 1 && c == m - 1) {
        if (aktualis_hossz > max_hossz) {
            max_hossz = aktualis_hossz;
        }
        return;
    }

    memo[r][c] = 1;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
            !memo[nr][nc] && hegy[nr][nc] >= hegy[r][c]) {
            
            keres(nr, nc, aktualis_hossz + 1);
        }
    }

    memo[r][c] = 0;
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &hegy[i][j]);
            memo[i][j] = 0;
        }
    }

    keres(0, 0, 1);

    if (max_hossz == -1) {
        printf("nincs megoldas\n");
    } else {
        printf("%d\n", max_hossz);
    }

    return 0;
}