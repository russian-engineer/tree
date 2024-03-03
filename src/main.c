#include "../include/tree.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    FILE *fp_graph = fopen("graphiz/bin_graph.dot", "w");
    assert(fp_graph != NULL);

    TreeNode RootTree = {NULL, NULL, NULL};
    
    int num = 0;

    while (printf("Введите число или 'q' для завершения: ") && fscanf(stdin, "%d", &num))
        AddElemTree(&RootTree, num);
    
    fprintf(fp_graph, "digraph {\n");
    CreateGraph(&RootTree, fp_graph);
    fprintf(fp_graph, "}");
    fclose(fp_graph);
            
    PrintTree(&RootTree);
    CleanTree(&RootTree);
}
