#include <stdio.h>
#include <stdlib.h>
#include "graphprofile.h"

int main(int argc, char const *argv[]) {
    int tc, n, i, j, ans, ret;
    int **g;
    scanf("%d", &tc);
    while(tc--) {
        printf("New testcase begin...\n");
        scanf("%d", &n);
        g = (int**) malloc(n * sizeof(int*));
        for (i = 0; i < n; i++) {
            g[i] = (int*) malloc(n * sizeof(int));
            for (j = 0; j < n; j++) {
                scanf("%d", &g[i][j]);
            }
        }

        //AvgDegreeTest
        scanf("%d", &ans);
        ret = avgDegree(g, n);
        if(ret == ans) {
            printf("AvgDegreeTest passed.\n");
        } else {
            printf("AvgDegreeTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //IsRegularTest
        scanf("%d", &ans);
        ret = isRegular(g, n);
        if(ret == ans) {
            printf("IsRegularTest passed.\n");
        } else {
            printf("IsRegularTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //IsCompleteTest
        scanf("%d", &ans);
        ret = isComplete(g, n);
        if(ret == ans) {
            printf("IsCompleteTest passed.\n");
        } else {
            printf("IsCompleteTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //IsCycleTest
        scanf("%d", &ans);
        ret = isCycleGraph(g, n);
        if(ret == ans) {
            printf("IsCycleTest passed.\n");
        } else {
            printf("IsCycleTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //IsPathTest
        scanf("%d", &ans);
        ret = isPathGraph(g, n);
        if(ret == ans) {
            printf("IsPathTest passed.\n");
        } else {
            printf("IsPathTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //HasEulerCktTest
        scanf("%d", &ans);
        ret = hasEulerCkt(g, n);
        if(ret == ans) {
            printf("HasEulerCktTest passed.\n");
        } else {
            printf("HasEulerCktTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //HasEulerPathTest
        scanf("%d", &ans);
        ret = hasEulerPath(g, n);
        if(ret == ans) {
            printf("HasEulerPathTest passed.\n");
        } else {
            printf("HasEulerPathTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        //OresTheoremTest
        scanf("%d", &ans);
        ret = satifiesOresTheorem(g, n);
        if(ret == ans) {
            printf("OresTheoremTest passed.\n");
        } else {
            printf("OresTheoremTest ***FAILED***! ");
            printf("(Expected: %d, Returned: %d)\n", ans, ret);
        }

        for (i = 0; i < n; i++) {
            free(g[i]);
        }
        free(g);
        printf("\n%d testcase left.\n\n", tc);
    }
    return 0;
}
