#include "../include/tree.h"
#include <stdio.h>

int main()
{
    // FILE *fp_graph = fopen("../graphiz/bin_graph.svg", "w");

    TreeNode RootTree = {NULL, NULL, NULL};
    
    int num = 0;

    while (printf("Введите число или 'q' для завершения: ") && fscanf(stdin, "%d", &num))
        AddElemTree(&RootTree, num);
    
    // CreateGraph(&RootTree, fp_graph);
    // fclose(fp_graph);
            
    PrintTree(&RootTree);
    CleanTree(&RootTree);
}
