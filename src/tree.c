#include "../include/tree.h"
#include <stdio.h>

printf(
printf()
printf()
printf(;

#endif /* ifdef MACRO */
#ifndef MACRO

#endif /* ifndef MACRO */
#ifndef ;wq

#endif /* ifndef ;wq */
#endif /* ifndef MACRO */

#ifndef MACRO

#endif /* ifndef MACRO */

#ifndef MACRO

#endif /* ifndef MACRO */

#ifndef ;w

#endif /* ifndef ;w */

int AddElemTree(TreeNode *root, int new_elem)
{
    printf();

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
            return 1;
    }
    
    return 0;
}

int RemoveElemTree(TreeNode *root, int rem_elem)
{
    if (*root->data == rem_elem)
    {
        if (!root->LeftNode && !root->RightNode)
        {
            free(root->data);
            return 1;
        }
        else if (!root->LeftNode && root->RightNode)
        {
            free(root->data);
            TreeNode *tmp = root->RightNode;
            memcpy(root, root->RightNode, sizeof(TreeNode));
            free(tmp);
            return 2;
        }
        else if (root->LeftNode && !root->RightNode)
        {
            free(root->data);
            TreeNode *tmp = root->LeftNode;
            memcpy(root, root->LeftNode, sizeof(TreeNode));
            free(tmp);
            return 2;
        }
        else 
        {
            TreeNode *before_min = root;
            TreeNode *min_elem_r = root->RightNode;
            while (min_elem_r->LeftNode)
            {
                before_min = min_elem_r;
                min_elem_r = min_elem_r->LeftNode;
            }
            
            free(root->data);
            root->data = min_elem_r->data;
            if (!min_elem_r->LeftNode && !min_elem_r->RightNode)
            {
                free(min_elem_r);
                before_min->LeftNode = NULL;
            }
            else if (!min_elem_r->LeftNode && min_elem_r->RightNode)
            {
                before_min->LeftNode = min_elem_r->RightNode;
                free(min_elem_r);
            }

            return 2;
        }
    }
    else 
    {
        if(root->LeftNode)
        {
            switch (RemoveElemTree(root->LeftNode, rem_elem))
            {
                case 1:
                    free(root->LeftNode);
                case 2:
                    return 2;
                    break;            
                
                case 0:
                    break;
                
                default:
                    return -7;
                    break;
            }
        }

        if(root->RightNode)
        {
            switch (RemoveElemTree(root->RightNode, rem_elem))
            {
                case 1:
                    free(root->RightNode);
                case 2:
                    return 2;
                    break;            
                
                case 0:
                    break;
                
                default:
                    return -7;
                    break;
            }
        }

        return 0;
    }
    return 0;
}

int PrintTree(TreeNode *root)
{
    printf("D:[%p] LN:[%p] RN:[%p] -- ", root->data, root->LeftNode, root->RightNode);
    if (root->data)
        printf("<<%d>>\n", *root->data);
    
    if (root->LeftNode)
        PrintTree(root->LeftNode);

    
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

int CreateGraph(TreeNode *root, FILE *fp)
{
    if (root->LeftNode)
    {
        fprintf(fp, "\t%d -> %d\n", *root->data, *root->LeftNode->data);
        CreateGraph(root->LeftNode, fp);
    } 
    if (root->RightNode)
    {
        fprintf(fp, "\t%d -> %d\n", *root->data, *root->RightNode->data);
        CreateGraph(root->RightNode, fp);
    }

    return 0;
}
