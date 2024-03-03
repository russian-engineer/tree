#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
    int *data;
    TreeNode *LeftNode;
    TreeNode *RightNode;
};

int AddElemTree(TreeNode *root, int new_elem);
int CleanTree(TreeNode *root);

int PrintTree(TreeNode *root);
int CreateGraph(TreeNode *node, FILE *fp);

#endif
