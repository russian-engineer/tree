#include "../include/tree.h"
#include <assert.h>
#include <cstdlib>
#include <stdlib.h>

int CompareElem(elem_t *elem1, elem_t *elem2)
{
    return *elem1 - *elem2;
}


int AddElemTree(TreeNode *node, elem_t *elem_ptr, size_t sz_elem)
{
    assert(node != NULL);
    assert(elem_ptr != NULL);

    if (node->life == 0)
    {
        node->life = 1;
        node->data = (elem_t *)malloc(sz_elem);
        memcpy(node->data, elem_ptr, sz_elem);
        node->RightNode = NULL;
        node->LeftNode = NULL;
    }
    else if (node->life == 1)
    {
        if (CompareElem(elem_ptr, node->data) > 0)
        {
            if (node->RightNode != NULL)
                AddElemTree(node->RightNode, elem_ptr, sz_elem);
            else
            {
                node->RightNode = (TreeNode *)malloc(sizeof(TreeNode));
                node->RightNode->life = 0;
                AddElemTree(node->RightNode, elem_ptr, sz_elem);
            }
        }
        else if (CompareElem(elem_ptr, node->data) < 0)
        {
            if (node->LeftNode != NULL)
                AddElemTree(node->LeftNode, elem_ptr, sz_elem);
            else
            {
                node->LeftNode = (TreeNode *)malloc(sizeof(TreeNode));
                node->LeftNode->life = 0;
                AddElemTree(node->LeftNode, elem_ptr, sz_elem);
            }
        }
        else 
            return 1;
    }
    else 
        return 1;
    
    return 0;
}

