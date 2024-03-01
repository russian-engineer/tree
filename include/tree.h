#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode TreeNode;
typedef int elem_t;

struct TreeNode {
    char     life;
    elem_t   *data;
    TreeNode *LeftNode;
    TreeNode *RightNode;
};

int AddElemTree(TreeNode *node, elem_t *elem_ptr, size_t sz_elem);
int CreateGraph(TreeNode *node, FILE *fp);
int PrintTree(TreeNode *node);
int CleanTree(TreeNode *node);

int CompareElem(elem_t *elem1, elem_t *elem2);


#endif
