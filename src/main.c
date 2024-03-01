#include "../include/tree.h"

int main()
{
    FILE *fp_graph = fopen("../graphiz/bin_graph.svg", "w");

    TreeNode RootTree = {0, NULL, NULL, NULL};

    elem_t num = 0;

    while (fscanf(stdin, "%d", &num) == 1)
        AddElemTree(&RootTree, &num, sizeof(elem_t));
    
    CreateGraph(&RootTree, fp_graph);
    fclose(fp_graph);

    PrintTree(&RootTree);
    CleanTree(&RootTree);
}
