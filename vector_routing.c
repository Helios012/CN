#include <stdio.h>
#include <stdlib.h>
int d[10][10], via[10][10];
int main() {
    int i, j, k, n, g[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the record for route %c:\n", i + 97);
        for (j = 0; j < n; j++) {
            printf("(%c : %c) :: ", i + 97, j + 97);
            scanf("%d", &g[i][j]);
            if (g[i][j] != 999)
                d[i][j] = 1;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            via[i][j] = i;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (d[i][j] == 1) {
                for (k = 0; k < n; k++) {
                    if (g[i][j] + g[j][k] < g[i][k]) {
                        g[i][k] = g[i][j] + g[j][k];
                        via[i][k] = j;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("Cost of route %c:\n", i + 97);
        for (j = 0; j < n; j++)
            printf("%c : %d via %c\n", j + 97, g[i][j], via[i][j] + 97);
    }
    return 0;


//  a::0         b::2         c::3         d::999
//   ::2          ::0          ::1          ::999
//   ::3          ::1          ::0          ::2
//   ::999        ::999        ::999        ::0
// }
