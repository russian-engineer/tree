#include "../include/tree.h"
#include <stdio.h>
#include <stdlib.h>

int AddElemTree(TreeNode *root, int new_elem)
{
    assert(root != NULL);

    if (!root->data)
    {
        root->data = (int *)malloc(sizeof(int));
        memcpy(root->data, &new_elem, sizeof(int));
    }
    else
    {
        if (new_elem > *root->data)
        {
            if (!root->RightNode)
                root->RightNode = (TreeNode *)calloc(1, sizeof(TreeNode));
                
            AddElemTree(root->RightNode, new_elem);
        }
        else if (new_elem < *root->data)
        {
            if (!root->LeftNode)
                root->LeftNode = (TreeNode *)calloc(1, sizeof(TreeNode));

            AddElemTree(root->LeftNode, new_elem);
        }
        else 
        {
            fprintf(stderr, "Ошибка: Такой элемент уже существует в дереве\n");
            return 1;
        }
    }
    
    return 0;
}

int PrintTree(TreeNode *root)
{
    if (root->LeftNode)
        PrintTree(root->LeftNode);

    printf("[%d]", *root->data);
    
    if (root->RightNode)
        PrintTree(root->RightNode);

    return 0;
}

int CleanTree(TreeNode *root)
{
    if (root->LeftNode)
    {
        CleanTree(root->LeftNode);
        free(root->LeftNode);
    }

    if (root->RightNode)
    {
        CleanTree(root->RightNode);
        free(root->RightNode);
    }

    free(root->data);

    return 0;
}
